#pragma once
#ifndef _BSTREE_H_
#define _BSTREE_H_
#include "../Tree/BTree.h"
template<typename T>
class BSTree :public BTree<T> {
private:
	//二叉排序树的非递归查找
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
	//对一个结点p进行递归查找key
	//p返回查找结果地址，fa保存父结点地址
	BTNode<T>* search_rec(BTNode<T>* p, T key, BTNode<T>*& fa) {
		if (!p || key == p->data)
			return p;
		fa = p;
		if (key < p->data)
			return search_rec(p->lc, key, fa);
		else
			return search_rec(p->rc, key, fa);
	}
	//删除p结点，其在父结点fa中的位置由sub代替
	void remove(BTNode<T>*& p, BTNode<T>*& fa, BTNode<T>* sub) {
		//被删结点无父结点则为根节点
		if (!fa)
			this->root = sub;
		if (fa->rc == p)
			fa->rc = sub;
		else if (fa->lc == p)
			fa->lc = sub;
		delete p;
	}
public:
	//插入操作，请勿调用父类的create()来进行创建
	void insert(T x) {
		BTNode<T>* fa, * p = search(x, fa);
		if (p)
			return;//若已存在则跳过
		p = new BTNode<T>(x);
		if (!this->root)
			this->root = p;
		else if (x < fa->data)
			fa->lc = p;
		else
			fa->rc = p;
	}
	//二叉排序树非递归查找
	BTNode<T>* search(T key) {
		BTNode<T>* fa = NULL;
		return search(key, fa);
	}
	//二叉排序树递归查找
	BTNode<T>* search_rec(T key) {
		BTNode<T>* fa = NULL;
		return search_rec(this->root, key, fa);
	}
	//二叉排序树删除结点值为x的结点
	void remove(T x) {
		BTNode<T>* p, * fa = NULL;
		p = search(x, fa);
		if (!p)
			return;
		//被删结点为叶结点
		if(!p->lc && !p->rc)
			remove(p, fa, NULL);
		//被删结点左子树为空，用其右子树替代
		else if (!p->lc)
			remove(p, fa, p->rc);
		//被删结点的右子树为空，用其左子树替代
		else if (!p->rc)
			remove(p, fa, p->lc);
		else
		{
			//若被删结点的左右子树均不为空，则用其右子树
			//替代被删结点，同时将被删结点的左子树
			//收为其中序遍历后继结点的左孩子
			BTNode<T>* child = p->rc;
			//找被删结点右子树中序遍历的后继结点
			while (child->lc)
				child = child->lc;
			//把被删结点的左子树收为child的左孩子
			child->lc = p->lc;
			remove(p, fa, p->rc);
		}
	}
};
#endif // !_BSTREE_H_
