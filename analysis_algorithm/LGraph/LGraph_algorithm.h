#pragma once
#ifndef _LGRAPH_ALGORITHM_H_
#define _LGRAPH_ALGORITHM_H_

#include "../Queue/Queue.h"
#include "../LGraph/LGraph.h"

//������ȱ����ݹ麯��
template<typename T>
void LGraph<T>::DFS(int u, bool* visited) {
	visited[u] = true;
	std::cout << AdjList[u].info().data << "->";
	LNode<VNode<T>>* p = AdjList[u].head();
	while (p != NULL) {
		int v = p->data.adjvex;
		//��ÿһ��δ���ʽ�����������ȱ���
		if (!visited[v]) {
			DFS(v, visited);
		}
		p = p -> next;
	}
}
//������ȱ���
template<typename T>
void LGraph<T>::DFS() {
	//��¼����Ƿ񱻷���
	bool* visited = new bool[this->n]();
	std::cout << "������ȱ�����ͼ�Ľ����\n";
	for (int i = 0; i < this->n; i++) {
		if (!visited[i]) {
			DFS(i, visited);
		}
	}
	std::cout << "���\n";
	delete[] visited;
}
//������ȱ���
template<typename T>
void LGraph<T>::BFS() {
	bool* visited = new bool[this->n]();
	std::cout << "������ȱ�����ͼ�Ľ����\n";
	//ʹ�ö��м�¼������ȱ�������
	Queue<int> Q;
	for (int i = 0; i < this->n; i++) {
		if (!visited[i]) {
			Q.enqueue(i);
			visited[i] = true;
			while (!Q.empty()) {
				//ȡ�����ж�ͷ����
				int u = Q.dequeue();
				std::cout << AdjList[u].info().data << "->";
				//������ͷ�������ڵĶ���
				LNode<VNode<T>>* p = AdjList[u].head();
				while (p != NULL) {
					int v = p->data.adjvex;
					//��δ�����������
					if (!visited[v]) {
						Q.enqueue(v);
						visited[v] = true;
					}
					p = p->next;
				}
			}
		}
	}
	std::cout << "���\n";
	delete[] visited;
}

//������������
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
//��������
template<typename T>
bool LGraph<T>::TopologicalSort() {
	int count = 0;
	int* indegree = getIndegree();
	Stack<int> S;
	for (int i = 0; i < this->n; i++) {
		if (!indegree[i])
			S.push(i);
	}
	std::cout << "��ͼ����������Ϊ��\n";
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
//�������򣬹ؼ�·��ʱʹ��
//ִ�к�������緢��ʱ��������������е�ջ
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
			//�������緢��ʱ��
			if (ve[u] + p->data.weight > ve[v])
				ve[v] = ve[u] + p->data.weight;
			p = p->next;
		}
	}
	return count = this->n;
}
//�ؼ�·��
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
	std::cout << "��*�ĻΪͼ�ؼ�·���ϵĻ\n";
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
