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
	//Ĭ������ͼ�ı�Ϊһ�Ի���ı�
	int edges() const {
		return e;
	}
	virtual T& vertex(int u) = 0;//ָ�����������
	virtual int locate(T e) = 0;//ͨ���������ݲ�ѯ����
	virtual int& weight(int u, int v) = 0;//��(u,v)��Ȩֵ
	virtual bool exist(int u, int v) = 0;//��(u,v)�Ƿ����
	virtual void insert(T const& u) = 0;//����һ������
	//�ڶ���u��v֮�����һ��Ȩ��Ϊw�ı�
	virtual void insert(int u, int v, int w) = 0;
	virtual void print() = 0;//���ͼ�Ľṹ
};
//����֮��ͷ�ļ��д�����ӡ��ĺ���
//Ĭ�ϴ���Ϊ����ͼ��isdir�ж��Ƿ�������ͼ
void create_Graph(Graph<char>* G, bool isdir = false) {
	char c;
	cout << "������ͼ�Ķ��㣬��Ctrl+Z����:\n";
	while (cin >> c) {
		G->insert(c);
		cout << "��" << G->vertices() << "����Ϊ:" << c << '\n';
	}
	cin.clear();//����cin��״̬��ʶ��
	rewind(stdin);//������뻺����
	char u, v;
	int w;
	cout << "������ͼ�еıߣ���u��v��ȨֵΪw����Ctrl+z����:" << endl;
	while (cin >> u >> v >> w) {
		int i = G->locate(u);
		int j = G->locate(v);
		if (i < 0 || j < 0) {
			cout << "���������������������...\n";
		}
		else {
			G->insert(i, j, w);
			//����ͼʱ���ڽӶ��ر���⣩
			if (!isdir) {
				G->insert(j, i, w);
			}
		}
	}
	cin.clear();
	rewind(stdin);
}
void print_Graph(Graph<char>* G) {
	cout << "ͼ����" << G->vertices() << "���㣬"
		<< G->edges() << "���ߣ�����ͼ�������Σ�:\n";
	cout << "-----------------------------------------------------------\n";
	G->print();
	cout << "-----------------------------------------------------------\n";
}

#endif