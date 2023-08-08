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
	//���캯��
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
	//���ڶ������е�һ�����Ĵ�����'#'Ϊ��
	BTNode<T>* insert() {
		T c;
		cin >> c;
		cout << c;
		if (c == '#')
			return NULL;
		BTNode<T>* t = new BTNode<T>(c, insert(), insert());
		return t;
	}
	//�ݹ���пռ��ͷ�(�������)
	void remove(BTNode<T>* t) {
		if (t == NULL)
			return;
		remove(t->lc);
		remove(t->rc);
		delete t;
	}
	//���ʽ��ʱ���еĲ������˴��������
	//���Ϊ�麯����������д���ܲ�����д��������
	virtual void visit(BTNode<T>* t) {
		cout << t->data << ' ';
	}
	//ǰ������ĵݹ麯��
	void preOrder(BTNode<T>* t) {
		if (t == NULL)
			return;
		visit(t);
		preOrder(t->lc);
		preOrder(t->rc);
	}
	//��������ĵݹ麯��
	void inOrder(BTNode<T>* t) {
		if (t == NULL)
			return;
		inOrder(t->lc);
		visit(t);
		inOrder(t->rc);
	}
	//��������ĵݹ麯��
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
	//�ݹ鴴��������(ǰ�����)
	void create() {
		root = insert();
	}
	//�ݹ��ǰ�����
	void preOrder() {
		preOrder(root);
	}
	//�ݹ���������
	void inOrder() {
		inOrder(root);
	}
	//�ݹ�ĺ������
	void postOrder() {
		postOrder(root);
	}
	//�ǵݹ��ǰ�����
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
	//�ǵݹ���������
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
	//�ǵݹ�ĺ������
	void postOrder_iter() {
		//ջ�нṹ�壬ָ���㲢��¼�ܷ��ջ
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
			//���ջ��Ԫ���ܷ��ջ��ֻ�е����η��ʲ��ܳ�ջ
			while (!s.empty() && s.top()->flag) {
				t = s.top()->node;
				visit(t);
				s.pop();
			}
			//�ǿմ���ջ��Ԫ�صڶ��α������꣬��һ�ο��Գ�ջ
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