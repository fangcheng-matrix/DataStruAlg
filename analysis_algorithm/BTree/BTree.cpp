#include "BTree.h"
#include <iostream>
using namespace std;

void test01() {
	BTree<char> T;
	cout << "�밴ǰ��������������ݣ�#������Ϊ�գ���\n";
	T.create();
	cout << "\n�ö�����ǰ������Ľ��Ϊ��\n";
	T.preOrder();
	cout << "\n�ö�������������Ľ��Ϊ��\n";
	T.inOrder();
	cout << "\n�ö�������������Ľ��Ϊ��\n";
	T.postOrder();
	cout << endl;
}
void test02() {
	BTree<char> T;
	cout << "�밴ǰ��������������ݣ�#������Ϊ�գ���\n";
	T.create();
	cout << "\n�ö�����ǰ������Ľ��Ϊ��\n";
	T.preOrder_iter();
	cout << "\n�ö�������������Ľ��Ϊ��\n";
	T.inOrder_iter();
	cout << "\n�ö�������������Ľ��Ϊ��\n";
	T.postOrder_iter();
	cout << endl;
}

int main() {
	//test01();
	test02();

	system("pause");
	return 0;
}