#include "MGraph.h"
#include "MGraph_algorithm.h"
#include <iostream>

using namespace std;

void test01() {
	//通过父类指针指向不同子类来实现图的多态
	Graph<char>* G = new MGraph<char>();
	create_Graph(G, true);//有向图
	print_Graph(G);
}
void test02() {
	//通过父类指针指向不同子类来实现图的多态
	Graph<char>* G = new MGraph<char>();
	create_Graph(G);//无向图
	print_Graph(G);
	MGraph<char>* MG = dynamic_cast<MGraph<char>*>(G);
	if (MG) {
		MG->Prim();
	}
}
void test03() {
	//通过父类指针指向不同子类来实现图的多态
	Graph<char>* G = new MGraph<char>();
	create_Graph(G);//无向图
	print_Graph(G);
	MGraph<char>* MG = dynamic_cast<MGraph<char>*>(G);
	if (MG) {
		MG->Kruskal();
	}
}
void test04() {
	//通过父类指针指向不同子类来实现图的多态
	Graph<char>* G = new MGraph<char>();
	create_Graph(G, true);//有向图
	print_Graph(G);
	MGraph<char>* MG = dynamic_cast<MGraph<char>*>(G);
	if (MG) {
		cout << "请输入起始顶点：";
		char c;
		cin >> c;
		MG->ShortestPsth_DIJ(MG->locate(c));
	}
}
void test05() {
	//通过父类指针指向不同子类来实现图的多态
	Graph<char>* G = new MGraph<char>();
	create_Graph(G, true);//有向图
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