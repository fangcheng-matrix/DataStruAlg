#pragma once
#ifndef _BSTREE_H_
#define _BSTREE_H_
#include "../Tree/BTree.h"
template<typename T>
class BSTree :public BTree<T> {
private:
	//�����������ķǵݹ����
	BTNode<T>* search(T key, BTNode<T>*& fa) {
		BTNode<T>* p = this->root;
		while (p) {
			if (key == p->data)
				break;
			fa = p;
			p = (key < p->data) ? p->lc : p->rc;
		}
		return p;
	}
	//��һ�����p���еݹ����key
	//p���ز��ҽ����ַ��fa���游����ַ
	BTNode<T>* search_rec(BTNode<T>* p, T key, BTNode<T>*& fa) {
		if (!p || key == p->data)
			return p;
		fa = p;
		if (key < p->data)
			return search_rec(p->lc, key, fa);
		else
			return search_rec(p->rc, key, fa);
	}
	//ɾ��p��㣬���ڸ����fa�е�λ����sub����
	void remove(BTNode<T>*& p, BTNode<T>*& fa, BTNode<T>* sub) {
		//��ɾ����޸������Ϊ���ڵ�
		if (!fa)
			this->root = sub;
		if (fa->rc == p)
			fa->rc = sub;
		else if (fa->lc == p)
			fa->lc = sub;
		delete p;
	}
public:
	//���������������ø����create()�����д���
	void insert(T x) {
		BTNode<T>* fa, * p = search(x, fa);
		if (p)
			return;//���Ѵ���������
		p = new BTNode<T>(x);
		if (!this->root)
			this->root = p;
		else if (x < fa->data)
			fa->lc = p;
		else
			fa->rc = p;
	}
	//�����������ǵݹ����
	BTNode<T>* search(T key) {
		BTNode<T>* fa = NULL;
		return search(key, fa);
	}
	//�����������ݹ����
	BTNode<T>* search_rec(T key) {
		BTNode<T>* fa = NULL;
		return search_rec(this->root, key, fa);
	}
	//����������ɾ�����ֵΪx�Ľ��
	void remove(T x) {
		BTNode<T>* p, * fa = NULL;
		p = search(x, fa);
		if (!p)
			return;
		//��ɾ���ΪҶ���
		if(!p->lc && !p->rc)
			remove(p, fa, NULL);
		//��ɾ���������Ϊ�գ��������������
		else if (!p->lc)
			remove(p, fa, p->rc);
		//��ɾ����������Ϊ�գ��������������
		else if (!p->rc)
			remove(p, fa, p->lc);
		else
		{
			//����ɾ����������������Ϊ�գ�������������
			//�����ɾ��㣬ͬʱ����ɾ����������
			//��Ϊ�����������̽�������
			BTNode<T>* child = p->rc;
			//�ұ�ɾ�����������������ĺ�̽��
			while (child->lc)
				child = child->lc;
			//�ѱ�ɾ������������Ϊchild������
			child->lc = p->lc;
			remove(p, fa, p->rc);
		}
	}
};
#endif // !_BSTREE_H_
