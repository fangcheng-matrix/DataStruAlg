#include "MGraph.h"
#include "MGraph_algorithm.h"
#include <iostream>

using namespace std;

void test01() {
	//ͨ������ָ��ָ��ͬ������ʵ��ͼ�Ķ�̬
	Graph<char>* G = new MGraph<char>();
	create_Graph(G, true);//����ͼ
	print_Graph(G);
}
void test02() {
	//ͨ������ָ��ָ��ͬ������ʵ��ͼ�Ķ�̬
	Graph<char>* G = new MGraph<char>();
	create_Graph(G);//����ͼ
	print_Graph(G);
	MGraph<char>* MG = dynamic_cast<MGraph<char>*>(G);
	if (MG) {
		MG->Prim();
	}
}
void test03() {
	//ͨ������ָ��ָ��ͬ������ʵ��ͼ�Ķ�̬
	Graph<char>* G = new MGraph<char>();
	create_Graph(G);//����ͼ
	print_Graph(G);
	MGraph<char>* MG = dynamic_cast<MGraph<char>*>(G);
	if (MG) {
		MG->Kruskal();
	}
}
void test04() {
	//ͨ������ָ��ָ��ͬ������ʵ��ͼ�Ķ�̬
	Graph<char>* G = new MGraph<char>();
	create_Graph(G, true);//����ͼ
	print_Graph(G);
	MGraph<char>* MG = dynamic_cast<MGraph<char>*>(G);
	if (MG) {
		cout << "��������ʼ���㣺";
		char c;
		cin >> c;
		MG->ShortestPsth_DIJ(MG->locate(c));
	}
}
void test05() {
	//ͨ������ָ��ָ��ͬ������ʵ��ͼ�Ķ�̬
	Graph<char>* G = new MGraph<char>();
	create_Graph(G, true);//����ͼ
	print_Graph(G);
	MGraph<char>* MG = dynamic_cast<MGraph<char>*>(G);
	if (MG) {
		MG->ShortestPath_Floyd();
	}
}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	test05();
	return 0;
}