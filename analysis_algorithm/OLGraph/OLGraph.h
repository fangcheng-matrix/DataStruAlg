#pragma once
#ifndef _OLGRAPH_H_
#define _OLGRAPH_H_
#include "../Vector/Vector.h"
#include "../Graph/Graph.h"
#include <iostream>
using namespace std;

struct ArcBox {
	int tailvex, headvex, weight;
	ArcBox* hlink, * tlink;
	ArcBox() :hlink(NULL), tlink(NULL) { }
	ArcBox(int t, int h, int w = INT_MAX,
		ArcBox* h1 = NULL, ArcBox* t1 = NULL)
		:tailvex(t), headvex(h), weight(w),
		hlink(h1), tlink(t1) { }
};
template<typename T>
struct VNode {
	T data;//顶点信息
	ArcBox* firstIn, * firstOut;//该顶点的第一条入弧和出弧
	VNode() :firstIn(NULL), firstOut(NULL) { }
	VNode(T e,ArcBox *i=NULL,ArcBox *o=NULL)
		:data(e),firstIn(i),firstOut(o) { }
};

template <typename T>
class OLGraph :public Graph<T> {
private:
	Vector<VNode<T>> OList;
public:
	T& vertex(int u) {
		return OList[u].data;
	}
	int locate(T e) {
		int i = 0;
		while (i < this->n) {
			if (vertex(i) == e) {
				return i;
			}
			else {
				i++;
			}
		}
		return -1;
	}
	int& weight(int u, int v) {
		ArcBox* p = OList[u].firstOut;
		while (p != NULL) {
			if (p->headvex == v) {
				return p->weight;
			}
			else {
				p = p->tlink;
			}
		}
	}
	bool exist(int u, int v) {
		if (u<0 || u>this->n)
			return false;
		if (v<0 || v>this->n)
			return false;
		ArcBox* p = OList[u].firstOut;
		while (p != NULL) {
			if (p->headvex == v) {
				return true;
			}
			else {
				p = p->tlink;
			}
		}
		return false;
	}
	void insert(T const& u) {
		OList.insert(VNode<T>(u));
		this->n++;
	}
	void insert(int u, int v, int w) {
		if (u<0 || u>this->n)
			return;
		if (v<0 || v>this->n)
			return;
		if (exist(u, v))
			return;
		ArcBox* p = new ArcBox(u, v, w, OList[v].firstIn, OList[u].firstOut);
		OList[v].firstIn = p;
		OList[u].firstOut = p;
		this->e++;
	}
	void print() {
		cout << "编号\t头结点\t弧结点链表\n";
		for (int i = 0; i < this->n; i++) {
			printf("%4d\t", i);
			cout << vertex(i) << '\t';
			ArcBox* p = OList[i].firstOut;
			while (p != NULL) {
				printf("|%d|%d|\t", p->tailvex, p->headvex);
				p = p->tlink;
			}
			cout << '\n';
		}
	}
};
#endif