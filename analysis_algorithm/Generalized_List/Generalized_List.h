#pragma once
#ifndef NULL
#define NULL 0
#endif // !NULL
#include <iostream>
using namespace std;

template<typename T>
struct GLNode {
	int tag;
	union {
		T data;
		//ptr�Ǳ����ָ����ptr.hp��ptr.tp�ֱ�ָ���ͷ�ͱ�β
		struct {
			GLNode<T>* hp, * tp;
		} ptr;
	};
	//���캯��
	GLNode() { };
	GLNode(T _data) :data(_data) {
		tag = 0;
	}
	GLNode(GLNode<T>* h, GLNode<T>* t) {
		ptr.hp = h;
		ptr.tp = t;
		tag = 1;
	}
};

template<typename T>
class GList {
private:
	GLNode<T>* head;
	//�ݹ齨�������Ĵ洢�ṹ
	void create(GLNode<T>*& p, char*& ch) {
		++ch;
		//cout << *ch << endl;
		//��Ϊ"("��ݹ齨���ӱ�
		if (*ch == '(') {
			p = new GLNode<T>(NULL, NULL);
			create(p->ptr.hp, ch);
		}
		//��Ϊ")"�����ձ������ַ�����ԭ�ӽ��
		else if (*ch != ')') {
			GLNode<T>* t = new GLNode<T>(*ch);
			p = new GLNode<T>(t, NULL);
		}
		else {
			p = NULL;
			return;
		}
		//��Ϊ","��ݹ鹹���̱�
		if (*(++ch) == ',') {
			create(p->ptr.tp, ch);
		}
	}

	int depth(GLNode<T>* p) {
		if (p == NULL)
			return 0;
		if (p->tag == 0)
			return 0;
		int dhp = depth(p->ptr.hp) + 1,
			dtp = depth(p->ptr.tp);
		return dhp > dtp ? dhp : dtp;
	}
public:
	//���캯����Ĭ�ϱ�Ϊ��
	GList() {
		head = NULL;
	}
	//���ع����ͷ���
	GLNode<T>* header() const {
		return head;
	}
	//���ع������
	int length() const {
		int cnt = 0;
		for (GLNode<T>* p = head; p != NULL && p->tag == 1; p = p->ptr.tp)
			cnt++;
		return cnt;
	}
	//�����ַ������������洢�ṹ
	bool create(char* ch) {
		//cout << *ch << endl;
		if (*ch != '(')
			return false;
		create(head, ch);
		if (*ch != ')')
			return false;
		return true;
	}
	int depth() {
		int dhp = depth(head->ptr.hp) + 1,
			dtp = depth(head->ptr.tp);
		return dhp > dtp ? dhp : dtp;
	}
};