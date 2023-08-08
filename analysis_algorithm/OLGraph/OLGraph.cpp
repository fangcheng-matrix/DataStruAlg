#include "OLGraph.h"
#include <iostream>
using namespace std;

void test01() {
	//通过父类指针指向不同的子类来实现图的多态
	Graph<char>* G = new OLGraph<char>();
	create_Graph(G, true);
	print_Graph(G);
}

int main() {
	test01();

	return 0;
}