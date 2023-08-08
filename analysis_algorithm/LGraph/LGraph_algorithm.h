#pragma once
#ifndef _LGRAPH_ALGORITHM_H_
#define _LGRAPH_ALGORITHM_H_

#include "../Queue/Queue.h"
#include "../LGraph/LGraph.h"

//深度优先遍历递归函数
template<typename T>
void LGraph<T>::DFS(int u, bool* visited) {
	visited[u] = true;
	std::cout << AdjList[u].info().data << "->";
	LNode<VNode<T>>* p = AdjList[u].head();
	while (p != NULL) {
		int v = p->data.adjvex;
		//对每一个未访问结点进行深度优先遍历
		if (!visited[v]) {
			DFS(v, visited);
		}
		p = p -> next;
	}
}
//深度优先遍历
template<typename T>
void LGraph<T>::DFS() {
	//记录结点是否被访问
	bool* visited = new bool[this->n]();
	std::cout << "深度优先遍历该图的结果：\n";
	for (int i = 0; i < this->n; i++) {
		if (!visited[i]) {
			DFS(i, visited);
		}
	}
	std::cout << "完成\n";
	delete[] visited;
}
//广度优先遍历
template<typename T>
void LGraph<T>::BFS() {
	bool* visited = new bool[this->n]();
	std::cout << "广度优先遍历该图的结果：\n";
	//使用队列记录广度优先遍历次序
	Queue<int> Q;
	for (int i = 0; i < this->n; i++) {
		if (!visited[i]) {
			Q.enqueue(i);
			visited[i] = true;
			while (!Q.empty()) {
				//取队列中队头顶点
				int u = Q.dequeue();
				std::cout << AdjList[u].info().data << "->";
				//遍历队头顶点相邻的顶点
				LNode<VNode<T>>* p = AdjList[u].head();
				while (p != NULL) {
					int v = p->data.adjvex;
					//若未访问则将其入队
					if (!visited[v]) {
						Q.enqueue(v);
						visited[v] = true;
					}
					p = p->next;
				}
			}
		}
	}
	std::cout << "完成\n";
	delete[] visited;
}

//计算各结点的入度
template<typename T>
int* LGraph<T>::getIndegree() {
	int* indegree = new int[this->n]();
	for (int i = 0; i < this->n; i++) {
		LNode<VNode<T>>* p = AdjList[i].head();
		while (p != NULL) {
			indegree[p->data.adjvex]++;
			p = p->next;
		}
	}
	return indegree;
}
//拓扑排序
template<typename T>
bool LGraph<T>::TopologicalSort() {
	int count = 0;
	int* indegree = getIndegree();
	Stack<int> S;
	for (int i = 0; i < this->n; i++) {
		if (!indegree[i])
			S.push(i);
	}
	std::cout << "该图的拓扑序列为：\n";
	while (!S.empty()) {
		int u = S.pop();
		std::cout << '\t' << vertex(u);
		count++;
		LNode<VNode<T>>* p = AdjList[u].head();
		while (p != NULL) {
			int v = p->data.adjvex;
			if (--indegree[v] == 0)
				S.push(v);
			p = p->next;
		}
	}
	return count == this->n;
}
//拓扑排序，关键路径时使用
//执行后产生最早发生时间数组和拓扑序列的栈
template<typename T>
bool LGraph<T>::TopologicalOrder(int*& ve, Stack<int>& S) {
	int count = 0;
	int* indegree = getIndegree();
	ve = new int[this->n]();
	Stack<int> SS;
	for (int i = 0; i < this->n; i++) {
		if (!indegree[i])
			SS.push(i);
	}
	while (!SS.empty()) {
		int u = SS.pop();
		S.push(u);
		count++;
		LNode<VNode<T>>* p = AdjList[u].head();
		while (p != NULL) {
			int v = p->data.adjvex;
			if (--indegree[v] == 0)
				SS.push(v);
			//更新最早发生时间
			if (ve[u] + p->data.weight > ve[v])
				ve[v] = ve[u] + p->data.weight;
			p = p->next;
		}
	}
	return count = this->n;
}
//关键路径
template<typename T>
bool LGraph<T>::CirticalPath() {
	int* ve;
	Stack<int> S;
	if (!TopologicalOrder(ve, S))
		return false;
	int* vl = new int[this->n];
	for (int i = 0; i < this->n; i++)
		vl[i] = ve[S.top()];
	while (!S.empty()) {
		int u = S.pop();
		LNode<VNode<T>>* p = AdjList[u].head();
		while (p != NULL) {
			int v = p->data.adjvex, dut = p->data.weight;
			if (vl[u] > vl[u] - dut)
				vl[u] = vl[v] - dut;
			p = p->next;
		}
	}
	std::cout << "标*的活动为图关键路径上的活动\n";
	std::cout << "<Vi,Vj>\t" << "dut\t" << "ee\t" << "el\t" << "(*)\n";
	for (int i = 0; i < this->n; i++) {
		LNode<VNode<T>>* p = AdjList[i].head();
		while (p != NULL) {
			int j = p->data.adjvex, dut = p->data.weight;
			std::cout << '<' << vertex(i) << ',' << vertex(j) << ">\t";
			std::cout << dut << '\t' << ve[i] << '\t' << vl[j] - dut << '\t';
			if (ve[i] == vl[j] - dut)
				std::cout << "*";
			std::cout << '\n';
			p = p->next;
		}
	}
	delete[] ve;
	delete[] vl;
	return true;
}
#endif // !_LGRAPH_ALGORITHM_H_
