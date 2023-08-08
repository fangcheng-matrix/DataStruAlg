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
		//ptr是表结点的指针域，ptr.hp和ptr.tp分别指向表头和表尾
		struct {
			GLNode<T>* hp, * tp;
		} ptr;
	};
	//构造函数
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
	//递归建立广义表的存储结构
	void create(GLNode<T>*& p, char*& ch) {
		++ch;
		//cout << *ch << endl;
		//若为"("则递归建立子表
		if (*ch == '(') {
			p = new GLNode<T>(NULL, NULL);
			create(p->ptr.hp, ch);
		}
		//若为")"则建立空表，其他字符建立原子结点
		else if (*ch != ')') {
			GLNode<T>* t = new GLNode<T>(*ch);
			p = new GLNode<T>(t, NULL);
		}
		else {
			p = NULL;
			return;
		}
		//若为","则递归构造后继表
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
	//构造函数，默认表为空
	GList() {
		head = NULL;
	}
	//返回广义表头结点
	GLNode<T>* header() const {
		return head;
	}
	//返回广义表长度
	int length() const {
		int cnt = 0;
		for (GLNode<T>* p = head; p != NULL && p->tag == 1; p = p->ptr.tp)
			cnt++;
		return cnt;
	}
	//利用字符串建立广义表存储结构
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