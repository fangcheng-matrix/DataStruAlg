#pragma once
#ifndef _B_TREE_H_
#define _B_TREE_H_

#include "../Vector/Vector.h"
#include <iostream>

template<typename T>
struct B_TNode {
	B_TNode* parent;//指向双亲指针
	Vector<T> key;//关键字向量
	Vector<B_TNode*>child;//子树指针向量
	//开始有0个关键字和1个空子树指针
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
	B_TNode<T>* ptr;//指向找到的结点
	int pos;//在结点中的关键字序号
	bool tag;//是否查找成功
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
	//递归释放空间
	void release(B_TNode<T>* p) {
		if (p = NULL)
			return;
		for (int i = 0; i < p->child.size(); i++)
			release(p->child[i]);
		delete p;
	}
	//中序遍历递归实现
	void print(B_TNode<T>* p) {
		if (p = NULL)
			return;
		print(p->child[0]);
		for (int i = 0; i < p->key.size(); i++) {
			std::cout << " " << p->key[i];
			print(p->child[i + 1]);
		}
	}
	//在t指向的结点中，寻找小于或等于key的最大关键字序号
	int search(B_TNode<T>* t, T key) {
		int i;
		for (i = 0; i < t->key.size() && t->key[i] <= key; i++);
		return i - 1;
	}
	//通过分裂修复B-树的q结点
	void split(B_TNode<T>* q) {
		//结点阶数大于或等于M，则进行结点的分裂调整
		if (q->key.size() < order)
			return;
		//阶数除以2向上取整，下标1计数
		int mid = (order - 1) / 2 + 1;
		int n = order - mid;
		//p为分裂后的右孩子
		B_TNode<T>* p = new B_TNode<T>();
		for (int i = 0; i < n; i++) {
			//删除是0下标计数
			p->key.insert(i, q->key.remove(mid));
			p->child.insert(i, q->child.remove(mid));
		}
		p->child[order - mid] = q->child.remove(mid);
		//若子结点非空则将其父结点统一指向p
		if (p->child[0])
			for (int i = 0; i < p->child.size(); i++)
				p->child[i]->parent = p;
		//fa指向新的父结点
		B_TNode<T>* fa = q->parent;
		//不存在即为根结点
		if (!fa)
			this->root = fa = new B_TNode<T>(q->key.remove(mid - 1), q, p);
		else {
			//找到mid结点在父结点的位置
			int pos = search(fa, q->key[0]) + 1;
			fa->key.insert(pos, q->key.remove(mid - 1));
			fa->child.insert(pos + 1, p);
			p->parent = fa;
			//递归分裂父结点
			split(fa);
		}
	}
	//通过合并修复B-树的q结点
	void merge(B_TNode<T>* q) {
		//当结点的关键字数量小于阶数除以2向上取整-1时
		//需要进行修复
		if (q->key.size() >= (order - 1) / 2)
			return;
		B_TNode<T>* fa = q->parent;
		//若当前结点为根结点，则关键字数至少为1
		if (!fa) {
			//若关键字已删除完，但还有唯一的孩子结点
			if (q->key.empty() && q->child[0]) {
				root = q->child[0];
				root->parent = NULL;
				delete q;
			}
			return;
		}
		int pos = 0;//确定q在fa结点中的位置
		while (fa->child[pos] != q)
			pos++;
		//向左兄弟借用关键字
		//q有左兄弟
		if (pos > 0) {
			B_TNode<T>* lb = fa->child[pos - 1];
			//左兄弟有足够的关键字借出
			if (lb->key.size() > (order - 1) / 2) {
				//q向fa借关键字
				q->key.insert(0, fa->key[pos - 1]);
				q->child.insert(0, lb->child.remove(lb->child.size() - 1));
				if (q->child[0])
					q->child[0]->parent = q;
				//fa借出的地方向lb借最后一个关键字
				fa->key[pos - 1] = lb->key.remove(lb->key.size() - 1);
				return;
			}
		}
		//向右兄弟借关键字
		//q有右兄弟
		if (pos < fa->child.size() - 1) {
			B_TNode<T>* rb = fa->child[pos + 1];
			//右兄弟有足够的关键字借出
			if (rb->key.size() > (order - 1) / 2) {
				//q向fa借关键字
				q->key.insert(0, fa->key[pos]);
				if (rb->child[0])
					rb->child[0]->parent = q;
				q->child.insert(rb->child.remove(0));
				//fa借出的地方向lb借最后一个关键字
				fa->key[pos] = rb->key.remove(0);
				return;
			}
		}
		//不能向左右兄弟借关键字时进行合并操作
		B_TNode<T>* l, * r;
		//存在左兄弟，与其合并
		if (pos > 0) {
			r = q;
			l = fa->child[pos - 1];
			//移除fa与q的关系
			fa->child.remove(pos);
			//lb向fa中借一个关键字
			l->key.insert(fa->key.remove(pos - 1));
		}
		//存在右兄弟，与其合并
		else {
			r = fa->child[pos + 1];
			l = q;
			//移除fa与右兄弟的关系
			fa->child.remove(pos + 1);
			q->key.insert(fa->key.remove(pos));
		}
		//将r结点合并到l结点
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
		merge(fa);//递归修复父结点
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
	查找关键字k，返回结果
	若查找成功，则指针ptr所指结点中第pos个关键字等于k；
	否则，关键字k应插入ptr所指结点中
	第pos个和第pos+1个关键字之间
	*/
	Result<T>search(T k) {
		int pos;
		B_TNode<T>* p = root, * q = NULL;
		while (p) {
			//查找最大不大于k的序号
			pos = search(p, k);
			//找到关键字
			if (pos >= 0 && p->key[pos] == k)
				return Result<T>(p, pos, true);
			//未找到
			else {
				q = p;//定位当前结点
				p = p->child[pos + 1];//在子结点中继续寻找
			}
		}
		//退出循环则未找到关键字
		return Result<T>(q, pos, false);
	}
	//插入关键字k，若已存在关键字则返回false
	//否则，插入成功返回true
	bool insert(T k) {
		if (root == NULL) {
			root = new B_TNode<T>(k);
			size++;
			return true;
		}
		Result<T>r = search(k);
		if (r.tag)
			return false;//查找成功，已存在关键字
		r.ptr->key.insert(r.pos + 1, k);
		r.ptr->child.insert(r.pos + 2, NULL);
		size++;
		split(r.ptr);//向上分裂
		return true;
	}
	//删除关键字k，若不存在关键字则返回false；
	//否则，删除成功返回true
	bool remove(T k) {
		Result<T>r = search(k);
		if (!r.tag)
			return false;
		//不是叶结点
		if (r.ptr->child[0]) {
			//用其后一个子树的最左侧结点代替
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
