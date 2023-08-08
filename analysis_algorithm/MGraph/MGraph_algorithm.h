#pragma once
#ifndef _MGRAPH_ALGORITHM_H_
#define _MGRAPH_ALGORITHM_H_

#include "../Sort/Heap.h"
#include "../Tree/DisjSets.h"
#include "MGraph.h"

//Prim算法从u点开始（编号为0的点）构造最小生成树
template<typename T>
void MGraph<T>::Prim(int u) {
	//Prim算法辅助结构体
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
		std::cout << "起始点错误！\n";
		return;
	}
	//初始化辅助数组
	closedge closedges[7];//closedge closedges[this->n];
	for (int i = 0; i < this->n; i++) {
		if (i != u) {
			closedges[i] = closedge(u, E[u][i]);
		}
		else {
			closedges[i].lowcost = 0;
		}
	}
	std::cout << "该图的最小生成树上的边为：\n";
	//Prim算法
	for(int i = 1; i < this->n; i++) {
		//求辅助数组中边权最小的边所对应的序号
		int k, min = INT_MAX;
		for (int j = 0; j < this->n; j++) {
			if (closedges[j].lowcost != 0 && closedges[j].lowcost < min) {
				min = closedges[j].lowcost;
				k = j;
			}
		}
		if (min == INT_MAX) {
			std::cout << "此图不连通！\n";
			return;
		}
		std::cout << '(' << V[closedges[k].adjvex] << ',' << V[k] << ')';
		closedges[k].lowcost = 0;
		//更新辅助数组
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
	//边的结构体，在kruskal中应用
	struct Edge {
		int weight;
		int ivex, jvex;//该边依附的两个顶点的位置
		Edge() {

		}
		Edge(int i, int j, int w = INT_MAX)
			:weight(w), ivex(i), jvex(j) {

		}
		//重载‘<’运算符
		bool operator<(Edge edge) const {
			return this->weight < edge.weight;
		}
	};
	//使用并查集
	DisjSets S(this->n);
	MinHeap<Edge> H;
	//将无向图的所有边构造成最小堆
	for (int i = 0; i < this->n; i++) {
		for (int j = i + 1; j < this->n; j++) {
			if (exist(i, j))
				H.push(Edge(i, j, E[i][j]));
		}
	}
	//通过n-1趟选择，构造最小生成树
	std::cout << "最下生成树上的边为：\n";
	for (int i = 1; i < this->n; i++) {
		Edge edge = H.pop();
		while (S.inSame(edge.ivex, edge.jvex))
			edge = H.pop();
		std::cout << '(' << V[edge.ivex] << ',' << V[edge.jvex] << ')';
		S.unionSets(edge.ivex, edge.jvex);
	}
}
//Dijkstra算法
template<typename T>
void MGraph<T>::ShortestPsth_DIJ(int v0) {
	if (v0 < 0 || v0 >= this->n)
		return;
	//最短路径长度
	int* ShortPathTable = new int[this->n];
	//若PathMatrix[v][w]为TRUE
	//则w是从v0到v当前求的最短路径上的顶点
	bool** PathMatrix = new bool* [this->n];
	for (int i = 0; i < this -> n; i++)
		PathMatrix[i] = new bool[this->n]();
	//final[v]为TRUE，当且仅当v属于V-S,即已经求得v0到v的最短路径
	//final[v]为TRUE，即将v加入S
	bool* final = new bool[this->n]();
	for (int i = 0; i < this->n; i++) {
		ShortPathTable[i] = E[v0][i];
		if (ShortPathTable[i] < INT_MAX) {
			PathMatrix[i][v0] = true;
			PathMatrix[i][i] = true;
		}
	}
	//开始主循环n-1次
	//每次求得v0到某个v顶点的最短路径，并加V到S集
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
		//更新当前最短路径及距离
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
	//输出结果
	for (int i = 0; i < this->n; i++) {
		if (i == v0)
			continue;
		std::cout << V[v0] << "->" << V[i] << '\t';
		if (ShortPathTable[i] < INT_MAX)
			std::cout << "最短路径长度=" << ShortPathTable[i] << "经过的顶点有：";
		else
			std::cout << "无路径";
		for (int j = 0; j < this->n; j++) {
			if (PathMatrix[i][j])
				std::cout << V[j] << ',';
		}
		std::cout << '\n';
	}
	//释放数组空间，避免内存泄漏
	for (int i = 0; i < this->n; i++)
		delete[] PathMatrix[i];
	delete[] PathMatrix;
	delete[] ShortPathTable;
}
//FLoyd算法
template<typename T>
void MGraph<T>::ShortestPath_Floyd() {
	//定义最短路矩阵与路径矩阵
	int** ShortPathTable = new int* [this->n];
	int** PathMatrix = new int* [this->n];
	for (int i = 0; i < this->n; i++) {
		//初始化数组
		ShortPathTable[i] = new int[this->n]();
		PathMatrix[i] = new int[this->n]();
		for (int j = 0; j < this -> n; j++) {
			ShortPathTable[i][j] = (i == j) ? 0 : E[i][j];
			PathMatrix[i][j] = j;
		}
	}
	//Floyd算法核心，3层循环
	for (int k = 0; k < this->n; k++) {
		for (int i = 0; i < this->n; i++) {
			for (int j = 0; j < this->n; j++) {
				if (ShortPathTable[i][k] == INT_MAX || ShortPathTable[k][j] == INT_MAX)
					continue;
				//发现由k中转更短时进行更新
				if (ShortPathTable[i][j] > ShortPathTable[i][k] + ShortPathTable[k][j]) {
					ShortPathTable[i][j] = ShortPathTable[i][k] + ShortPathTable[k][j];
					PathMatrix[i][j] = PathMatrix[i][k];
				}
			}
		}
	}
	//输出最短路矩阵
	std::cout << "最短路矩阵：\n";
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
	//输出多源最短路路径
	std::cout << "各结点间最短路路径为：\n";
	for (int i = 0; i < this->n; i++) {
		for (int j = 0; j < this->n; j++) {
			if (i == j)
				continue;
			if (ShortPathTable[i][j] < INT_MAX) {
				std::cout << V[i] << "->" << V[j] << ':' << "最短路径长度=" << ShortPathTable[i][j] << ",路径为：";
			}
			else
				continue;
			for (int k = i; k != j; k = PathMatrix[k][j]) {
				std::cout << V[k] << "->";
			}
			std::cout << V[j] << std::endl;
		}
	}
	//释放数组空间，避免内存泄露
	for (int i = 0; i < this->n; i++) {
		delete[] ShortPathTable[i];
		delete[] PathMatrix[i];
	}
	delete[] ShortPathTable;
	delete[] PathMatrix;
}
#endif // !_MGRAPH_ALGORITHM_H_
