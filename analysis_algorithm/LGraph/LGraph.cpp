#include "LGraph.h"
#include "LGraph_algorithm.h"
#include <iostream>
using namespace std;

void test01() {
	//通过父类指针指向不同子类来实现图的多态
	Graph<char>* G = new LGraph<char>();
	create_Graph(G);//无向图
	print_Graph(G);
}
void test02() {
	//通过父类指针指向不同子类来实现图的多态
	Graph<char>* G = new LGraph<char>();
	create_Graph(G, true);//有向图
	print_Graph(G);
}
void test03() {
	//通过父类指针指向不同子类来实现图的多态
	Graph<char>* G = new LGraph<char>();
	create_Graph(G);//无向图
	print_Graph(G);
	//以邻接表为例实现广度优先遍历
	LGraph<char>* LG = dynamic_cast<LGraph<char>*>(G);
	if (LG) {
		LG->BFS();
	}
}
void test04() {
	//通过父类指针指向不同子类来实现图的多态
	Graph<char>* G = new LGraph<char>();
	create_Graph(G, true);//有向图
	print_Graph(G);
	//以邻接表为例实现深度优先遍历
	LGraph<char>* LG = dynamic_cast<LGraph<char>*>(G);
	if (LG) {
		LG->DFS();
	}
}
void test05() {
	//通过父类指针指向不同子类来实现图的多态
	Graph<char>* G = new LGraph<char>();
	create_Graph(G, true);//有向图
	print_Graph(G);
	//以邻接表为例实现拓扑排序
	LGraph<char>* LG = dynamic_cast<LGraph<char>*>(G);
	if (LG) {
		if (!LG->TopologicalSort())
			cout << "\n该图中存在回路！\n";
	}
}
void test06() {
	//通过父类指针指向不同子类来实现图的多态
	Graph<char>* G = new LGraph<char>();
	create_Graph(G, true);//有向图
	print_Graph(G);
	//以邻接表为例实现拓扑排序
	LGraph<char>* LG = dynamic_cast<LGraph<char>*>(G);
	if (LG) {
		if (!LG->CirticalPath())
			cout << "\n该图中存在回路！\n";
	}
}

int main() {
	//test01();
	//test02();

	//test03();
	//test04();
	//test05();
	test06();
	return 0;
}