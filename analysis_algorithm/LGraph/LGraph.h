#pragma once
#ifndef _LGRAPH_H_
#define _LGRAPH_H_

#include "../List/List.h"
#include "../Stack/Stack.h"
#include "../Vector/Vector.h"
#include "../Graph/Graph.h"
#include <iostream>

template <typename T>
struct VNode {
	int adjvex;
	T data;
	int weight;
	VNode() { }
	VNode(int a, T d, int w = INT_MAX)
		:adjvex(a), data(d), weight(w) {

	}
};

template <typename T>
class LGraph :public Graph<T> {
private:
	Vector<List<VNode<T>>> AdjList;
	//深度优先搜索算法
	void DFS(int u, bool* visited);
	//私有拓扑排序，关键路径时使用
	//执行后产生最早发生时间数组和拓扑序列的栈
	bool TopologicalOrder(int*& ve, Stack<int>& S);
	//深度优先遍历，求关节点用
	void dfs(int u, int fa, int& dfs_clock,
		int* dfn, int* low, bool* iscut,
		Stack<int>& S, Vector<Vector<int>>& bcc);
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
		return AdjList[u].info().data;
	}
	LNode<VNode<T>>* firstEdge(int u) {
		return AdjList[u].head();
	}
	int& weight(int u, int v) {
		LNode<VNode<T>>* p = AdjList[u].head();
		while (p != NULL) {
			if (p->data.adjvex == v)
				return p->data.weight;
		}
	}
	bool exist(int u, int v) {
		if (u<0 || u>this->n)
			return false;
		if (v<0 || v>this->n)
			return false;
		LNode<VNode<T>>* p = AdjList[u].head();
		while (p != NULL) {
			if (p->data.adjvex == v)
				return true;
			else p = p->next;
		}
		return false;
	}
	void insert(T const& u) {
		List<VNode<T>>* p = new List<VNode<T>>(VNode<T>(this->n, u));
		AdjList.insert(*p);
		this->n++;
	}
	void insert(int u, int v, int w) {
		if (u<0 || u>this->n)
			return;
		if (v<0 || v>this->n)
			return;
		if (exist(u, v))
			return;
		VNode<T>node = AdjList[v].info();
		node.weight = w;
		AdjList[u].insert(node);
		this->e++;
	}
	void print() {
		cout << "编号\t顶点\t相邻点编号\n";
		for (int i = 0; i < this->n; i++) {
			printf("%4d\t", i);
			cout << vertex(i) << '\t';
			LNode<VNode<T>>* p = AdjList[i].head();
			while (p != NULL) {
				printf("%3d", p->data.adjvex);
				p = p->next;
			}
			cout << endl;
		}
	}
	//计算各节点的入度
	int* getIndegree();
	void DFS();
	void BFS();
	//用邻接表实现拓扑排序
	bool TopologicalSort();
	//关键路径
	bool CirticalPath();
	//Tarjan算法求关节点和双连通分量（无向图）
	void Tarjan();
};

#endif // !_LGRAPH_H_
