#pragma once
#ifndef _AMLGRAPH_H_
#define _AMLGRAPH_H_

#include "../Vector/Vector.h"
#include "../Graph/Graph.h"
#include <iostream>
using namespace std;

//边结点
struct Edge {
	int weight;
	int ivex, jvex;
	Edge* ilink, * jlink;
	Edge():ilink(NULL),jlink(NULL){ }
	Edge(int i, int j, int w = INT_MAX, Edge* il = NULL, Edge* jl = NULL)
		:ivex(i), jvex(j), weight(w), ilink(il), jlink(jl) {

	}
};
template<typename T>
struct VexBox {
	T data;
	Edge* firstEdge;
	VexBox() :firstEdge(NULL) {

	}
	VexBox(T e, Edge* f = NULL)
		:data(e), firstEdge(f) {

	}
};

template<typename T>
class AMLGraph :public Graph<T> {
private:
	Vector<VexBox<T>> AMList;
public:
	T& vertex(int u) {
		return AMList[u].data;
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
		Edge* p = AMList[u].firstEdge;
		while (p != NULL) {
			if (p->ivex == u) {
				if (p->jvex == v) {
					return p->weight;
				}
				else {
					p = p->ilink;
				}
			}
			else if (p->ivex == v){
				return p->weight;
			}
			else {
				p = p->jlink;
			}
		}
	}
	bool exist(int u, int v) {
		if (u<0 || u>this->n)
			return false;
		if (v<0 || v>this->n)
			return false;
		Edge* p = AMList[u].firstEdge;
		while (p != NULL) {
			if (p->ivex == u) {
				if (p->jvex == v) {
					return true;
				}
				else {
					p = p->ilink;
				}
			}
			else if (p->ivex == v) {
				return true;
			}
			else {
				p = p->jlink;
			}
		}
		return false;
	}
	void insert(T const& u) {
		AMList.insert(VexBox<T>(u));
		this->n++;
	}
	void insert(int u, int v, int w) {
		if (u<0 || u>this->n)
			return;
		if (v<0 || v>this->n)
			return;
		if (exist(u, v))
			return;
		Edge* p = new Edge(u, v, w, AMList[u].firstEdge, AMList[v].firstEdge);
		AMList[u].firstEdge = p;
		AMList[v].firstEdge = p;
		this->e++;
	}
	void print() {
		cout << "编号\t头结点\t边结点链表\n";
		for (int i = 0; i < this->n; i++) {
			printf("%4d\t", i);
			cout << vertex(i) << '\t';
			Edge* p = AMList[i].firstEdge;
			while (p != NULL) {
				printf("|%d|%d|\t", p->ivex, p->jvex);
				if (p->ivex == i) {
					p = p->ilink;
				}
				else {
					p = p->jlink;
				}
			}
			cout << '\n';
		}
	}
};
#endif // !_AMLGRAPH_H_
