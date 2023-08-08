#pragma once
#ifndef _BTREE_H_
#define _BTREE_H
#include <iostream>
#include <stack>
using namespace std;

template<typename T>
struct BTNode {
	T data;
	BTNode<T>* lc, * rc;
	//构造函数
	BTNode() :lc(NULL), rc(NULL) {

	}
	BTNode(T e, BTNode<T>* _lc = NULL, BTNode<T>* _rc = NULL)
		:data(e), lc(_rc), rc(_lc) {

	}
};

template <typename T>
class BTree {
protected:
	BTNode<T>* root;
	//对于二叉树中的一个结点的创建，'#'为空
	BTNode<T>* insert() {
		T c;
		cin >> c;
		cout << c;
		if (c == '#')
			return NULL;
		BTNode<T>* t = new BTNode<T>(c, insert(), insert());
		return t;
	}
	//递归进行空间释放(后序遍历)
	void remove(BTNode<T>* t) {
		if (t == NULL)
			return;
		remove(t->lc);
		remove(t->rc);
		delete t;
	}
	//访问结点时进行的操作，此处仅做输出
	//设计为虚函数，子类重写就能不必重写遍历函数
	virtual void visit(BTNode<T>* t) {
		cout << t->data << ' ';
	}
	//前序遍历的递归函数
	void preOrder(BTNode<T>* t) {
		if (t == NULL)
			return;
		visit(t);
		preOrder(t->lc);
		preOrder(t->rc);
	}
	//中序遍历的递归函数
	void inOrder(BTNode<T>* t) {
		if (t == NULL)
			return;
		inOrder(t->lc);
		visit(t);
		inOrder(t->rc);
	}
	//后序遍历的递归函数
	void postOrder(BTNode<T>* t) {
		if (t == NULL)
			return;
		postOrder(t->lc);
		postOrder(t->rc);
		visit(t);
	}
public:
	BTree() { 
		root = NULL; 
	}
	BTree(BTNode<T>* t) {
		root = t;
	}
	~BTree() {
		remove(root);
	}
	//递归创建二叉树(前序遍历)
	void create() {
		root = insert();
	}
	//递归的前序遍历
	void preOrder() {
		preOrder(root);
	}
	//递归的中序遍历
	void inOrder() {
		inOrder(root);
	}
	//递归的后序遍历
	void postOrder() {
		postOrder(root);
	}
	//非递归的前序遍历
	void preOrder_iter() {
		BTNode<T>* t = root;
		stack<BTNode<T>*> s;
		while (t || !s.empty()) {
			while (t) {
				visit(t);
				s.push(t);
				t = t->lc;
			}
			if (s.top()) {
				t = s.top(); 
				s.pop();
				t = t->rc;
			}
		}
	}
	//非递归的中序遍历
	void inOrder_iter() {
		BTNode<T>* t = root;
		stack<BTNode<T>*> s;
		while (t || !s.empty()) {
			while (t) {
				s.push(t);
				t = t->lc;
			}
			if (s.top()) {
				t = s.top();
				s.pop();
				visit(t);
				t = t->rc;
			}
		}
	}
	//非递归的后序遍历
	void postOrder_iter() {
		//栈中结构体，指向结点并记录能否出栈
		struct SNode {
			BTNode<T>* node;
			bool flag;
			SNode(BTNode<T>* t = NULL)
				:node(t), flag(false) {

			}
		};
		BTNode<T>* t = root;
		stack<SNode*> s;
		while (t || !s.empty()) {
			while (t) {
				s.push(new SNode(t));
				t = t->lc;
			}
			//检查栈顶元素能否出栈，只有第三次访问才能出栈
			while (!s.empty() && s.top()->flag) {
				t = s.top()->node;
				visit(t);
				s.pop();
			}
			//非空代表栈顶元素第二次被访问完，下一次可以出栈
			if (!s.empty()) {
				s.top()->flag = true;
				t = s.top()->node;
				t = t->rc;
			}
			else
				t = NULL;
		}
	}
};
#endif // !_BTREE_H_