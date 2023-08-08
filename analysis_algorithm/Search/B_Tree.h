#pragma once
#ifndef _B_TREE_H_
#define _B_TREE_H_

#include "../Vector/Vector.h"
#include <iostream>

template<typename T>
struct B_TNode {
	B_TNode* parent;//ָ��˫��ָ��
	Vector<T> key;//�ؼ�������
	Vector<B_TNode*>child;//����ָ������
	//��ʼ��0���ؼ��ֺ�1��������ָ��
	B_TNode() {
		parent = NULL;
		child.insert(NULL);
	}
	B_TNode(T e, B_TNode<T>* lc = NULL, B_TNode<T>* rc = NULL) {
		parent = NULL;
		key.insert(e);
		child.insert(lc);
		child.insert(rc);
		if (lc)
			lc->parent = this;
		if (rc)
			rc->parent = this;
	}
};
template<typename T>
struct Result {
	B_TNode<T>* ptr;//ָ���ҵ��Ľ��
	int pos;//�ڽ���еĹؼ������
	bool tag;//�Ƿ���ҳɹ�
	Result(B_TNode<T>* p, int i, bool t)
		:ptr(p), pos(i), tag(t) {

	}
};
template<typename T>
class B_Tree {
private:
	B_TNode<T>* root;
	int size;
	int order;
	//�ݹ��ͷſռ�
	void release(B_TNode<T>* p) {
		if (p = NULL)
			return;
		for (int i = 0; i < p->child.size(); i++)
			release(p->child[i]);
		delete p;
	}
	//��������ݹ�ʵ��
	void print(B_TNode<T>* p) {
		if (p = NULL)
			return;
		print(p->child[0]);
		for (int i = 0; i < p->key.size(); i++) {
			std::cout << " " << p->key[i];
			print(p->child[i + 1]);
		}
	}
	//��tָ��Ľ���У�Ѱ��С�ڻ����key�����ؼ������
	int search(B_TNode<T>* t, T key) {
		int i;
		for (i = 0; i < t->key.size() && t->key[i] <= key; i++);
		return i - 1;
	}
	//ͨ�������޸�B-����q���
	void split(B_TNode<T>* q) {
		//���������ڻ����M������н��ķ��ѵ���
		if (q->key.size() < order)
			return;
		//��������2����ȡ�����±�1����
		int mid = (order - 1) / 2 + 1;
		int n = order - mid;
		//pΪ���Ѻ���Һ���
		B_TNode<T>* p = new B_TNode<T>();
		for (int i = 0; i < n; i++) {
			//ɾ����0�±����
			p->key.insert(i, q->key.remove(mid));
			p->child.insert(i, q->child.remove(mid));
		}
		p->child[order - mid] = q->child.remove(mid);
		//���ӽ��ǿ����丸���ͳһָ��p
		if (p->child[0])
			for (int i = 0; i < p->child.size(); i++)
				p->child[i]->parent = p;
		//faָ���µĸ����
		B_TNode<T>* fa = q->parent;
		//�����ڼ�Ϊ�����
		if (!fa)
			this->root = fa = new B_TNode<T>(q->key.remove(mid - 1), q, p);
		else {
			//�ҵ�mid����ڸ�����λ��
			int pos = search(fa, q->key[0]) + 1;
			fa->key.insert(pos, q->key.remove(mid - 1));
			fa->child.insert(pos + 1, p);
			p->parent = fa;
			//�ݹ���Ѹ����
			split(fa);
		}
	}
	//ͨ���ϲ��޸�B-����q���
	void merge(B_TNode<T>* q) {
		//�����Ĺؼ�������С�ڽ�������2����ȡ��-1ʱ
		//��Ҫ�����޸�
		if (q->key.size() >= (order - 1) / 2)
			return;
		B_TNode<T>* fa = q->parent;
		//����ǰ���Ϊ����㣬��ؼ���������Ϊ1
		if (!fa) {
			//���ؼ�����ɾ���꣬������Ψһ�ĺ��ӽ��
			if (q->key.empty() && q->child[0]) {
				root = q->child[0];
				root->parent = NULL;
				delete q;
			}
			return;
		}
		int pos = 0;//ȷ��q��fa����е�λ��
		while (fa->child[pos] != q)
			pos++;
		//�����ֵܽ��ùؼ���
		//q�����ֵ�
		if (pos > 0) {
			B_TNode<T>* lb = fa->child[pos - 1];
			//���ֵ����㹻�Ĺؼ��ֽ��
			if (lb->key.size() > (order - 1) / 2) {
				//q��fa��ؼ���
				q->key.insert(0, fa->key[pos - 1]);
				q->child.insert(0, lb->child.remove(lb->child.size() - 1));
				if (q->child[0])
					q->child[0]->parent = q;
				//fa����ĵط���lb�����һ���ؼ���
				fa->key[pos - 1] = lb->key.remove(lb->key.size() - 1);
				return;
			}
		}
		//�����ֵܽ�ؼ���
		//q�����ֵ�
		if (pos < fa->child.size() - 1) {
			B_TNode<T>* rb = fa->child[pos + 1];
			//���ֵ����㹻�Ĺؼ��ֽ��
			if (rb->key.size() > (order - 1) / 2) {
				//q��fa��ؼ���
				q->key.insert(0, fa->key[pos]);
				if (rb->child[0])
					rb->child[0]->parent = q;
				q->child.insert(rb->child.remove(0));
				//fa����ĵط���lb�����һ���ؼ���
				fa->key[pos] = rb->key.remove(0);
				return;
			}
		}
		//�����������ֵܽ�ؼ���ʱ���кϲ�����
		B_TNode<T>* l, * r;
		//�������ֵܣ�����ϲ�
		if (pos > 0) {
			r = q;
			l = fa->child[pos - 1];
			//�Ƴ�fa��q�Ĺ�ϵ
			fa->child.remove(pos);
			//lb��fa�н�һ���ؼ���
			l->key.insert(fa->key.remove(pos - 1));
		}
		//�������ֵܣ�����ϲ�
		else {
			r = fa->child[pos + 1];
			l = q;
			//�Ƴ�fa�����ֵܵĹ�ϵ
			fa->child.remove(pos + 1);
			q->key.insert(fa->key.remove(pos));
		}
		//��r���ϲ���l���
		if (r->child[0])
			r->child[0]->parent = 1;
		l->child.insert(r->child.remove(0));
		while (!r->key.empty()) {
			l->key.insert(r->key.remove(0));
			if (r->child[0])
				r->child[0]->parent = l;
			l->child.insert(r->child.remove(0));
		}
		delete r;
		merge(fa);//�ݹ��޸������
	}
public:
	B_Tree(int m = 3) :root(NULL), size(0), order(m) {

	}
	~B_Tree() {
		release(root);
	}
	int Size() const {
		return size;
	}
	int Order() const {
		return order;
	}
	void print() {
		print(root);
	}
	/*
	���ҹؼ���k�����ؽ��
	�����ҳɹ�����ָ��ptr��ָ����е�pos���ؼ��ֵ���k��
	���򣬹ؼ���kӦ����ptr��ָ�����
	��pos���͵�pos+1���ؼ���֮��
	*/
	Result<T>search(T k) {
		int pos;
		B_TNode<T>* p = root, * q = NULL;
		while (p) {
			//������󲻴���k�����
			pos = search(p, k);
			//�ҵ��ؼ���
			if (pos >= 0 && p->key[pos] == k)
				return Result<T>(p, pos, true);
			//δ�ҵ�
			else {
				q = p;//��λ��ǰ���
				p = p->child[pos + 1];//���ӽ���м���Ѱ��
			}
		}
		//�˳�ѭ����δ�ҵ��ؼ���
		return Result<T>(q, pos, false);
	}
	//����ؼ���k�����Ѵ��ڹؼ����򷵻�false
	//���򣬲���ɹ�����true
	bool insert(T k) {
		if (root == NULL) {
			root = new B_TNode<T>(k);
			size++;
			return true;
		}
		Result<T>r = search(k);
		if (r.tag)
			return false;//���ҳɹ����Ѵ��ڹؼ���
		r.ptr->key.insert(r.pos + 1, k);
		r.ptr->child.insert(r.pos + 2, NULL);
		size++;
		split(r.ptr);//���Ϸ���
		return true;
	}
	//ɾ���ؼ���k���������ڹؼ����򷵻�false��
	//����ɾ���ɹ�����true
	bool remove(T k) {
		Result<T>r = search(k);
		if (!r.tag)
			return false;
		//����Ҷ���
		if (r.ptr->child[0]) {
			//�����һ������������������
			B_TNode<T>* t = r.ptr->child[r.pos + 1];
			while (t->child[0])
				t = t->child[0];
			r.ptr->key[r.pos] = t->key[0];
			r.ptr = t;
			r.pos = 0;
		}
		r.ptr->key.remove(r.pos);
		r.ptr->child.remove(r.pos + 1);
		size--;
		merge(r.ptr);
		return true;
	}
};
#endif // !_B_TREE_H_
