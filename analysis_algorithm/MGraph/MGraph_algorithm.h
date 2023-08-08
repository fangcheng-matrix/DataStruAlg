#pragma once
#ifndef _MGRAPH_ALGORITHM_H_
#define _MGRAPH_ALGORITHM_H_

#include "../Sort/Heap.h"
#include "../Tree/DisjSets.h"
#include "MGraph.h"

//Prim�㷨��u�㿪ʼ�����Ϊ0�ĵ㣩������С������
template<typename T>
void MGraph<T>::Prim(int u) {
	//Prim�㷨�����ṹ��
	struct closedge {
		int adjvex;
		int lowcost;
		closedge() {

		}
		closedge(int a, int l = INT_MAX)
			:adjvex(a), lowcost(l) {

		}
	};
	if (u < 0 || u >= this->n) {
		std::cout << "��ʼ�����\n";
		return;
	}
	//��ʼ����������
	closedge closedges[7];//closedge closedges[this->n];
	for (int i = 0; i < this->n; i++) {
		if (i != u) {
			closedges[i] = closedge(u, E[u][i]);
		}
		else {
			closedges[i].lowcost = 0;
		}
	}
	std::cout << "��ͼ����С�������ϵı�Ϊ��\n";
	//Prim�㷨
	for(int i = 1; i < this->n; i++) {
		//���������б�Ȩ��С�ı�����Ӧ�����
		int k, min = INT_MAX;
		for (int j = 0; j < this->n; j++) {
			if (closedges[j].lowcost != 0 && closedges[j].lowcost < min) {
				min = closedges[j].lowcost;
				k = j;
			}
		}
		if (min == INT_MAX) {
			std::cout << "��ͼ����ͨ��\n";
			return;
		}
		std::cout << '(' << V[closedges[k].adjvex] << ',' << V[k] << ')';
		closedges[k].lowcost = 0;
		//���¸�������
		for (int j = 0; j < this->n; j++) {
			if (E[k][j] < closedges[j].lowcost) {
				closedges[j] = closedge(k, E[k][j]);
			}
		}
	}
	std::cout << '\n';
}

template<typename T>
void MGraph<T>::Kruskal() {
	//�ߵĽṹ�壬��kruskal��Ӧ��
	struct Edge {
		int weight;
		int ivex, jvex;//�ñ����������������λ��
		Edge() {

		}
		Edge(int i, int j, int w = INT_MAX)
			:weight(w), ivex(i), jvex(j) {

		}
		//���ء�<�������
		bool operator<(Edge edge) const {
			return this->weight < edge.weight;
		}
	};
	//ʹ�ò��鼯
	DisjSets S(this->n);
	MinHeap<Edge> H;
	//������ͼ�����б߹������С��
	for (int i = 0; i < this->n; i++) {
		for (int j = i + 1; j < this->n; j++) {
			if (exist(i, j))
				H.push(Edge(i, j, E[i][j]));
		}
	}
	//ͨ��n-1��ѡ�񣬹�����С������
	std::cout << "�����������ϵı�Ϊ��\n";
	for (int i = 1; i < this->n; i++) {
		Edge edge = H.pop();
		while (S.inSame(edge.ivex, edge.jvex))
			edge = H.pop();
		std::cout << '(' << V[edge.ivex] << ',' << V[edge.jvex] << ')';
		S.unionSets(edge.ivex, edge.jvex);
	}
}
//Dijkstra�㷨
template<typename T>
void MGraph<T>::ShortestPsth_DIJ(int v0) {
	if (v0 < 0 || v0 >= this->n)
		return;
	//���·������
	int* ShortPathTable = new int[this->n];
	//��PathMatrix[v][w]ΪTRUE
	//��w�Ǵ�v0��v��ǰ������·���ϵĶ���
	bool** PathMatrix = new bool* [this->n];
	for (int i = 0; i < this -> n; i++)
		PathMatrix[i] = new bool[this->n]();
	//final[v]ΪTRUE�����ҽ���v����V-S,���Ѿ����v0��v�����·��
	//final[v]ΪTRUE������v����S
	bool* final = new bool[this->n]();
	for (int i = 0; i < this->n; i++) {
		ShortPathTable[i] = E[v0][i];
		if (ShortPathTable[i] < INT_MAX) {
			PathMatrix[i][v0] = true;
			PathMatrix[i][i] = true;
		}
	}
	//��ʼ��ѭ��n-1��
	//ÿ�����v0��ĳ��v��������·��������V��S��
	for (int i = 1; i < this->n; i++) {
		int min = INT_MAX, pos;
		for (int v = 0; v < this->n; v++) {
			if (!final[v]) {
				if (ShortPathTable[v] < min) {
					pos = v;
					min = ShortPathTable[v];
				}
			}
		}
		final[pos] = true;
		//���µ�ǰ���·��������
		for (int v = 0; v < this->n; v++) {
			if (v == v0 || !exist(pos, v))
				continue;
			else if (!final[v] && (min + E[pos][v] < ShortPathTable[v])) {
				ShortPathTable[v] = min + E[pos][v];
				for (int j = 0; j < this->n; j++)
					PathMatrix[v][j] = PathMatrix[pos][j];
				PathMatrix[v][v] = true;
			}
		}
	}
	//������
	for (int i = 0; i < this->n; i++) {
		if (i == v0)
			continue;
		std::cout << V[v0] << "->" << V[i] << '\t';
		if (ShortPathTable[i] < INT_MAX)
			std::cout << "���·������=" << ShortPathTable[i] << "�����Ķ����У�";
		else
			std::cout << "��·��";
		for (int j = 0; j < this->n; j++) {
			if (PathMatrix[i][j])
				std::cout << V[j] << ',';
		}
		std::cout << '\n';
	}
	//�ͷ�����ռ䣬�����ڴ�й©
	for (int i = 0; i < this->n; i++)
		delete[] PathMatrix[i];
	delete[] PathMatrix;
	delete[] ShortPathTable;
}
//FLoyd�㷨
template<typename T>
void MGraph<T>::ShortestPath_Floyd() {
	//�������·������·������
	int** ShortPathTable = new int* [this->n];
	int** PathMatrix = new int* [this->n];
	for (int i = 0; i < this->n; i++) {
		//��ʼ������
		ShortPathTable[i] = new int[this->n]();
		PathMatrix[i] = new int[this->n]();
		for (int j = 0; j < this -> n; j++) {
			ShortPathTable[i][j] = (i == j) ? 0 : E[i][j];
			PathMatrix[i][j] = j;
		}
	}
	//Floyd�㷨���ģ�3��ѭ��
	for (int k = 0; k < this->n; k++) {
		for (int i = 0; i < this->n; i++) {
			for (int j = 0; j < this->n; j++) {
				if (ShortPathTable[i][k] == INT_MAX || ShortPathTable[k][j] == INT_MAX)
					continue;
				//������k��ת����ʱ���и���
				if (ShortPathTable[i][j] > ShortPathTable[i][k] + ShortPathTable[k][j]) {
					ShortPathTable[i][j] = ShortPathTable[i][k] + ShortPathTable[k][j];
					PathMatrix[i][j] = PathMatrix[i][k];
				}
			}
		}
	}
	//������·����
	std::cout << "���·����\n";
	std::cout << "---------------------------------------------------------------------------\n";
	std::cout << "  ";
	for (int i = 0; i < this->n; i++) {
		std::cout << vertex(i) << " |";
		for (int j = 0; j < this->n; j++) {
			if (ShortPathTable[i][j] == INT_MAX)
				std::cout << "  INF";
			else
				printf("%4d", ShortPathTable[i][j]);
		}
		std::cout << " |\n";
	}
	//�����Դ���··��
	std::cout << "���������··��Ϊ��\n";
	for (int i = 0; i < this->n; i++) {
		for (int j = 0; j < this->n; j++) {
			if (i == j)
				continue;
			if (ShortPathTable[i][j] < INT_MAX) {
				std::cout << V[i] << "->" << V[j] << ':' << "���·������=" << ShortPathTable[i][j] << ",·��Ϊ��";
			}
			else
				continue;
			for (int k = i; k != j; k = PathMatrix[k][j]) {
				std::cout << V[k] << "->";
			}
			std::cout << V[j] << std::endl;
		}
	}
	//�ͷ�����ռ䣬�����ڴ�й¶
	for (int i = 0; i < this->n; i++) {
		delete[] ShortPathTable[i];
		delete[] PathMatrix[i];
	}
	delete[] ShortPathTable;
	delete[] PathMatrix;
}
#endif // !_MGRAPH_ALGORITHM_H_
