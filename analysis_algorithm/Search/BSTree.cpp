#include <iostream>
#include "BSTree.h"
#include "AVLTree.h"
#include "B_Tree.h"
#include "HashTable.h"
using namespace std;

void createBSTree(BSTree<int>& T) {
	cout << "请输入二叉排序树的结点序列：\n";
	int x;
	while (cin >> x)
		T.insert(x);
	cin.clear();//更改cin的状态标识符
	rewind(stdin);//清空输入缓存区
	cout << "中序遍历结果：";
	T.inOrder();
	cout << "\n------------------------------------------\n";
}
void searchBSTree(BSTree<int>& T) {
	int x;
cout << "请输入一个待查找的结点值：";
cin >> x;
if (T.search(x))
cout << "非递归查找发现该点。。。\n";
else
cout << "非递归查找未找到该点。。。\n";
if (T.search_rec(x))
cout << "递归查找发现该点。。。\n";
else
cout << "递归查找未找到该点。。。\n";
cout << "\n------------------------------------------\n";
}
void insertBSTree(BSTree<int>& T) {
	int x;
	cout << "请输入一个待查找的结点值：";
	cin >> x;
	T.insert(x);
	cout << "中序遍历结果：";
	T.inOrder();
	cout << "\n------------------------------------------\n";
}
void deleteBSTree(BSTree<int>& T) {
	int x;
	cout << "请输入一个待删除的结点值：";
	cin >> x;
	T.remove(x);
	cout << "中序遍历结果：";
	T.inOrder();
	cout << "\n------------------------------------------\n";
}
void BSTreetest() {
	BSTree<int> T;
	createBSTree(T);
	searchBSTree(T);
	insertBSTree(T);
	deleteBSTree(T);
}

void createAVLTree(AVLTree<int>& T) {
	cout << "请输入平衡二叉树的结点序列：\n";
	int x;
	while (cin >> x)
		T.insert(x);
	cin.clear();//更改cin状态标识符
	rewind(stdin);//清空输入缓存区
	cout << "中序遍历结果：";
	T.inOrder();
	cout << "\n------------------------------------------\n";
}
void searchAVLTree(AVLTree<int>& T) {
	int x;
	cout << "请输入一个待查找的结点值：";
	cin >> x;
	if (T.search(x))
		cout << "非递归查找发现该点。。。\n";
	else
		cout << "非递归查找未找到该点。。。\n";
	if (T.search_rec(x))
		cout << "递归查找发现该点。。。\n";
	else
		cout << "递归查找未找到该点。。。\n";
	cout << "\n------------------------------------------\n";
}
void insertAVLTree(AVLTree<int>& T) {
	int x;
	cout << "请输入一个插入的结点值：";
	cin >> x;
	T.insert(x);
	cout << "中序遍历结果：";
	T.inOrder();
	cout << "\n------------------------------------------\n";
}
void deleteAVLTree(AVLTree<int>& T) {
	int x;
	cout << "请输入一个待删除的结点值：";
	cin >> x;
	T.remove(x);
	cout << "中序遍历结果：";
	T.inOrder();
	cout << "\n------------------------------------------\n";
}
void AVLTreetest() {
	AVLTree<int> T;
	createAVLTree(T);
	searchAVLTree(T);
	insertAVLTree(T);
	deleteAVLTree(T);
}

void createB_Tree(B_Tree<int>& T) {
	int key;
	cout << "请输入B-树的关键字：\n";
	while (cin >> key)
		T.insert(key);
	cin.clear();
	rewind(stdin);
	cout << T.Order() << "阶B-树有" << T.Size() << "个结点：\n";
	T.print();
	cout << endl;
}
void searchB_Tree(B_Tree<int>& T) {
	int key;
	cout << "请输入要查找的关键字：";
	cin >> key;
	Result<int>result = T.search(key);
	if (result.tag)
		cout << "该关键字在B-树中首关键字为" << result.ptr->key[0] << "对应结点的第"
		<< result.pos + 1 << "个位置上。。。\n";
	else
		cout << "B-树中没有这个关键字。。。\n";
}
void insertB_Tree(B_Tree<int> &T){
	int key;
	cout << "输入要插入B-树的关键字：";
	cin >> key;
	if (T.insert(key)) {
		cout << "插入后的" << T.Order() << "阶B-树有" << T.Size() << "个结点：\n";
		T.print();
		cout << endl;
	}
	else
		cout << "B-树中已存在该关键字。。。\n";
}
void removeB_Tree(B_Tree<int>& T) {
	int key;
	cout << "输入要删除B-树的关键字：";
	cin >> key;
	if (T.insert(key)) {
		cout << "删除后的" << T.Order() << "阶B-树有" << T.Size() << "个结点：\n";
		T.print();
		cout << endl;
	}
	else
		cout << "B-树中不存在该关键字。。。\n";
}
void B_Treetest() {
	B_Tree<int> T(3);
	createB_Tree(T);
	searchB_Tree(T);
	insertB_Tree(T);
	removeB_Tree(T);
}

void createHashTable(HashTable<int>& H) {
	int key;
	cout << "请输入哈希表的关键字：\n";
	while (cin >> key)
		H.insert(key);
	cin.clear();
	rewind(stdin);
	cout << "建立的哈希表为：\n";
	H.print();
}
void searchHashTable(HashTable<int>& H) {
	do {
		int key;
		cout << "请输入待查找的关键字（-1退出）：";
		cin >> key;;
		rewind(stdin);
		if (key == -1)
			break;
		if (H.search(key))
			cout << "哈希表中有" << key << "这个关键字记录。。。\n";
		else
			cout << "哈希表中未找到指定元素。。。\n";
	} while (true);
}
void deleteHashTable(HashTable<int>& H) {
	int key;
	cout << "请输入要删除的关键字：";
	cin >> key;
	H.remove(key);
	cout << "删除后的哈希表为：\n";
	H.print();
}
void Hashtest() {
	HashTable<int> H;
	createHashTable(H);
	searchHashTable(H);
	deleteHashTable(H);
}

int main() {
	//BSTreetest();
	AVLTreetest();
	//B_Treetest();
	//Hashtest();
	return 0;
}