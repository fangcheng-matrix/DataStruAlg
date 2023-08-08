#include "AMLGraph.h"
using namespace std;

void test01() {
	//通过父类指针指向不同子类来实现图的多态
	Graph<char>* G = new AMLGraph<char>();
	create_Graph(G);
	print_Graph(G);
}

int main() {
	test01();

	return 0;
}
