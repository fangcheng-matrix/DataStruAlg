#include "LGraph.h"
#include "LGraph_algorithm.h"
#include <iostream>
using namespace std;

void test01() {
	//ͨ������ָ��ָ��ͬ������ʵ��ͼ�Ķ�̬
	Graph<char>* G = new LGraph<char>();
	create_Graph(G);//����ͼ
	print_Graph(G);
}
void test02() {
	//ͨ������ָ��ָ��ͬ������ʵ��ͼ�Ķ�̬
	Graph<char>* G = new LGraph<char>();
	create_Graph(G, true);//����ͼ
	print_Graph(G);
}
void test03() {
	//ͨ������ָ��ָ��ͬ������ʵ��ͼ�Ķ�̬
	Graph<char>* G = new LGraph<char>();
	create_Graph(G);//����ͼ
	print_Graph(G);
	//���ڽӱ�Ϊ��ʵ�ֹ�����ȱ���
	LGraph<char>* LG = dynamic_cast<LGraph<char>*>(G);
	if (LG) {
		LG->BFS();
	}
}
void test04() {
	//ͨ������ָ��ָ��ͬ������ʵ��ͼ�Ķ�̬
	Graph<char>* G = new LGraph<char>();
	create_Graph(G, true);//����ͼ
	print_Graph(G);
	//���ڽӱ�Ϊ��ʵ��������ȱ���
	LGraph<char>* LG = dynamic_cast<LGraph<char>*>(G);
	if (LG) {
		LG->DFS();
	}
}
void test05() {
	//ͨ������ָ��ָ��ͬ������ʵ��ͼ�Ķ�̬
	Graph<char>* G = new LGraph<char>();
	create_Graph(G, true);//����ͼ
	print_Graph(G);
	//���ڽӱ�Ϊ��ʵ����������
	LGraph<char>* LG = dynamic_cast<LGraph<char>*>(G);
	if (LG) {
		if (!LG->TopologicalSort())
			cout << "\n��ͼ�д��ڻ�·��\n";
	}
}
void test06() {
	//ͨ������ָ��ָ��ͬ������ʵ��ͼ�Ķ�̬
	Graph<char>* G = new LGraph<char>();
	create_Graph(G, true);//����ͼ
	print_Graph(G);
	//���ڽӱ�Ϊ��ʵ����������
	LGraph<char>* LG = dynamic_cast<LGraph<char>*>(G);
	if (LG) {
		if (!LG->CirticalPath())
			cout << "\n��ͼ�д��ڻ�·��\n";
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