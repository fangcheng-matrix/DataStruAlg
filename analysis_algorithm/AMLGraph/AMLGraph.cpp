#include "AMLGraph.h"
using namespace std;

void test01() {
	//ͨ������ָ��ָ��ͬ������ʵ��ͼ�Ķ�̬
	Graph<char>* G = new AMLGraph<char>();
	create_Graph(G);
	print_Graph(G);
}

int main() {
	test01();

	return 0;
}
