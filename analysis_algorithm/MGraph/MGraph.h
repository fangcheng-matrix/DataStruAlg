#pragma once
#ifndef _MGRAPH_H_
#define _MGRAPH_H_

#include <iostream>
#include "../Vector/Vector.h"
#include "../Graph/Graph.h"

using namespace std;
template <typename T>
class MGraph :public Graph<T> {
private:
	Vector<T> V;
	Vector<Vector<int>> E;
public:
	int locate(T e) {
		int i = 0;
		while (i < this->n) {
			if (vertex(i) == e)
				return i;
			else
				i++;
		}
		return -1;
	}
	T& vertex(int u) {
		return V[u];
	}
	int& weight(int u, int v) {
		return E[u][v];
	}
	bool exist(int u, int v) {
		if (u<0 || u>this->n)
			return false;
		if (v<0 || v>this->n)
			return false;
		if (E[u][v] == INT_MAX)
			return false;
		else
			return true;
	}
	void insert(T const& u) {
		V.insert(u);
		for (int i = 0; i < this->n; i++) {
			E[i].insert(INT_MAX);//已存在的顶点建立无穷大的边
		}
		this->n++;
		Vector<int>* t = new Vector<int>();
		for (int i = 0; i < this->n; i++) {
			t->insert(INT_MAX);//为新进入的点建立无穷大的边
		}
		E.insert(*t);
	}
	void insert(int u, int v, int w) {
		if (exist(u, v))
			return;
		E[u][v] = w;
		this->e++;
	}
	void print() {
		cout << "  ";
		for (int i = 0; i < this->n; i++) {
			cout << " " << vertex(i);
		}
		cout << endl;
		for (int i = 0; i < this->n; i++) {
			cout << vertex(i) << " |";
			for (int j = 0; j < this->n; j++) {
				if (exist(i, j))
					printf("%2d", weight(i, j));
				else
					cout << " *";
			}
			cout << " |" << endl;
		}
	}
	//Prim算法
	void Prim(int = 0);
	//Kruskal算法
	void Kruskal();
	//Dijkstra算法
	void ShortestPsth_DIJ(int);
	//Floyd算法
	void ShortestPath_Floyd();
};

#endif