#include "BTree.h"
#include <iostream>
using namespace std;

void test01() {
	BTree<char> T;
	cout << "请按前序输入二叉树数据（#代表结点为空）：\n";
	T.create();
	cout << "\n该二叉树前序遍历的结果为：\n";
	T.preOrder();
	cout << "\n该二叉树中序遍历的结果为：\n";
	T.inOrder();
	cout << "\n该二叉树后序遍历的结果为：\n";
	T.postOrder();
	cout << endl;
}
void test02() {
	BTree<char> T;
	cout << "请按前序输入二叉树数据（#代表结点为空）：\n";
	T.create();
	cout << "\n该二叉树前序遍历的结果为：\n";
	T.preOrder_iter();
	cout << "\n该二叉树中序遍历的结果为：\n";
	T.inOrder_iter();
	cout << "\n该二叉树后序遍历的结果为：\n";
	T.postOrder_iter();
	cout << endl;
}

int main() {
	//test01();
	test02();

	system("pause");
	return 0;
}