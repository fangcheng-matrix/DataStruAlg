#pragma once
#ifndef _AVLTREE_H_
#define _AAVLTREE_H_
#include "BSTree.h"
#define LH 1
#define EH 0
#define RH -1

template<typename T>
struct AVLNode :BTNode<T> {
	int bal;//ƽ������
	AVLNode() :BTNode<T>(), bal(0) {

	}
	AVLNode(T e,BTNode<T>* _lc=NULL,BTNode<T>* _rc=NULL)
		:BTNode<T>(e, _lc, _rc), bal(0) {

	}
};
template<typename T>
class AVLTree :public BSTree<T> {
private:
	//LL��ת�������µ����������
	AVLNode<T>* rotate_LL(AVLNode<T>* t) {
		AVLNode<T>* l = (AVLNode<T>*)t->lc;
		t->lc = l->rc;
		l->rc = t;
		if (l->bal == EH) {
			t->bal = LH;
			l->bal = RH;
		}
		else
			t->bal = l->bal = EH;
		return l;
	}
	//LR��ת�������µ����������
	AVLNode<T>* rotate_LR(AVLNode<T>* t) {
		AVLNode<T>* l = (AVLNode<T>*)t->lc;
		AVLNode<T>* lr = (AVLNode<T>*)l->rc;
		l->rc = lr->lc;
		lr->lc = l;
		t->lc = lr->rc;
		lr->rc = t;
		t->bal = (lr->bal == LH) ? RH : EH;
		l->bal = (lr->bal == RH) ? LH : EH;
		lr->bal = EH;
		return lr;
	}
	//RR��ת�������µ����������
	AVLNode<T>* rotate_RR(AVLNode<T>* t) {
		AVLNode<T>* r = (AVLNode<T>*)t->rc;
		t->rc = r->lc;
		r->lc = t;
		if (r->bal == EH) {
			t->bal = RH;
			r->bal = LH;
		}
		else
			t->bal = r->bal = EH;
		return r;
	}
	//RL��ת�������µ����������
	AVLNode<T>* rotate_RL(AVLNode<T>* t) {
		AVLNode<T>* r = (AVLNode<T>*)t->rc;
		AVLNode<T>* rl = (AVLNode<T>*)r->lc;
		r->lc = rl->rc;
		rl->rc = r;
		t->rc = rl->lc;
		rl->lc = t;
		t->bal = (rl->bal == RH) ? LH : EH;
		r->bal = (rl->bal == LH) ? RH : EH;
		rl->bal = EH;
		return rl;
	}
	//��������Ƿ�ƽ�Ⲣ������е���
	AVLNode<T>* adjust(AVLNode<T>* t) {
		if (t->bal > -2 && t->bal < 2)
			return t;
		if (t->bal == 2) {
			if (((AVLNode<T>*)t->lc)->bal == RH)
				return rotate_LR(t);
			else
				return rotate_LL(t);
		}
		else if (t->bal == -2) {
			if (((AVLNode<T>*)t->rc)->bal == LH)
				return rotate_RL(t);
			else
				return rotate_RR(t);
		}
	}
	//�����룬����ƽ����Ϣ
	int insert(T x, AVLNode<T>*& t) {
		if (!t) {
			t = new AVLNode<T>(x);
			return 1;
		}
		//���������в����½��
		if (x < t->data) {
			int result = insert(x, (AVLNode<T>*&)t->lc);
			if (!result)
				return 0;
			t->bal += result;
			t = adjust(t);
			return (t->bal == LH) ? 1 : 0;
		}
		//���������в����½��
		else if (x > t->data) {
			int result = insert(x, (AVLNode<T>*&)t->rc);
			if (!result)
				return 0;
			t->bal -= result;
			t = adjust(t);
			return (t->bal == RH) ? 1 : 0;
		}
		//�Ѵ��ڸý���򷵻�
		else 
			return 0;
	}
	//���ɾ��������ƽ����Ϣ
	int remove(T x, AVLNode<T>*& t) {
		if (!t)
			return 0;
		//����������ɾ�����
		if (x < t->data) {
			int result = remove(x, (AVLNode<T>*&)t->lc);
			if (!result)
				return 0;
			t->bal -= result;
			t = adjust(t);
			return (t->bal == EH) ? 1 : 0;
		}
		//����������ɾ�����
		else if (x > t->data) {
			int result = remove(x, (AVLNode<T>*&)t->rc);
			if (!result)
				return 0;
			t->bal += result;
			t = adjust(t);
			return (t->bal == EH) ? 1 : 0;
		}
		//�ҵ�ɾ�����
		else {
			if (t->lc && t->rc) {
				//������������С�����浱ǰ���
				AVLNode<T>* rmin = (AVLNode<T>*)t->rc;
				while (rmin->lc)
					rmin = (AVLNode<T>*)rmin->lc;
				t->data = rmin->data;
				int result;
				result = remove(rmin->data, (AVLNode<T>*&)t->rc);
				if (!result)
					return 0;
				t->bal += result;
				t = adjust(t);
				return (t->bal == EH) ? 1 : 0;
			}
			//���������ӻ��Һ��Ӵ���
			else {
				AVLNode<T>* tmp = t;
				if (t->lc)
					t = (AVLNode<T>*)t->lc;
				else if (t->rc)
					t = (AVLNode<T>*)t->rc;
				else
					t = NULL;
				delete tmp;
				return 1;
			}
		}
	}
public:
	//��д�������
	void insert(T x) {
		insert(x, (AVLNode<T>*&)this->root);
	}
	void remove(T x) {
		remove(x, (AVLNode<T>*&)this->root);
	}
	//��д���ʽ������������һ�����
	void visit(BTNode<T>* t) {
		AVLNode<T>* p = (AVLNode<T>*)t;
		std::cout << p->data << '(' << p->bal << ')';
	}
};
#endif // !_AVLTREE_H_
