#pragma once
#ifndef _GRAPH_H_
#define _GRAPH_H_
#include <iostream>

using namespace std;

template <typename T>
class Graph {
protected:
	int n, e;
public:
	Graph() {
		n = e = 0;
	}
	int vertices() const {
		return n;
	}
	//默认无向图的边为一对互逆的边
	int edges() const {
		return e;
	}
	virtual T& vertex(int u) = 0;//指定顶点的数据
	virtual int locate(T e) = 0;//通过顶点数据查询其编号
	virtual int& weight(int u, int v) = 0;//边(u,v)的权值
	virtual bool exist(int u, int v) = 0;//边(u,v)是否存在
	virtual void insert(T const& u) = 0;//插入一个顶点
	//在顶点u和v之间插入一条权重为w的边
	virtual void insert(int u, int v, int w) = 0;
	virtual void print() = 0;//输出图的结构
};
//除此之外头文件中创建打印表的函数
//默认创建为无向图，isdir判断是否是有向图
void create_Graph(Graph<char>* G, bool isdir = false) {
	char c;
	cout << "请输入图的顶点，以Ctrl+Z结束:\n";
	while (cin >> c) {
		G->insert(c);
		cout << "第" << G->vertices() << "个点为:" << c << '\n';
	}
	cin.clear();//更改cin的状态标识符
	rewind(stdin);//清空输入缓存区
	char u, v;
	int w;
	cout << "请输入图中的边（从u到v，权值为w），Ctrl+z结束:" << endl;
	while (cin >> u >> v >> w) {
		int i = G->locate(u);
		int j = G->locate(v);
		if (i < 0 || j < 0) {
			cout << "顶点输入错误，请重新输入...\n";
		}
		else {
			G->insert(i, j, w);
			//无向图时（邻接多重表除外）
			if (!isdir) {
				G->insert(j, i, w);
			}
		}
	}
	cin.clear();
	rewind(stdin);
}
void print_Graph(Graph<char>* G) {
	cout << "图共有" << G->vertices() << "个点，"
		<< G->edges() << "条边（无向图计数两次）:\n";
	cout << "-----------------------------------------------------------\n";
	G->print();
	cout << "-----------------------------------------------------------\n";
}

#endif