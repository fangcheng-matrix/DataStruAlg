#include "OLGraph.h"
#include <iostream>
using namespace std;

void test01() {
	//ͨ������ָ��ָ��ͬ��������ʵ��ͼ�Ķ�̬
	Graph<char>* G = new OLGraph<char>();
	create_Graph(G, true);
	print_Graph(G);
}

int main() {
	test01();

	return 0;
}