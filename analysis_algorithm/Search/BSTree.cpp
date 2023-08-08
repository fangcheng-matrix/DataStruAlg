#include <iostream>
#include "BSTree.h"
#include "AVLTree.h"
#include "B_Tree.h"
#include "HashTable.h"
using namespace std;

void createBSTree(BSTree<int>& T) {
	cout << "����������������Ľ�����У�\n";
	int x;
	while (cin >> x)
		T.insert(x);
	cin.clear();//����cin��״̬��ʶ��
	rewind(stdin);//������뻺����
	cout << "������������";
	T.inOrder();
	cout << "\n------------------------------------------\n";
}
void searchBSTree(BSTree<int>& T) {
	int x;
cout << "������һ�������ҵĽ��ֵ��";
cin >> x;
if (T.search(x))
cout << "�ǵݹ���ҷ��ָõ㡣����\n";
else
cout << "�ǵݹ����δ�ҵ��õ㡣����\n";
if (T.search_rec(x))
cout << "�ݹ���ҷ��ָõ㡣����\n";
else
cout << "�ݹ����δ�ҵ��õ㡣����\n";
cout << "\n------------------------------------------\n";
}
void insertBSTree(BSTree<int>& T) {
	int x;
	cout << "������һ�������ҵĽ��ֵ��";
	cin >> x;
	T.insert(x);
	cout << "������������";
	T.inOrder();
	cout << "\n------------------------------------------\n";
}
void deleteBSTree(BSTree<int>& T) {
	int x;
	cout << "������һ����ɾ���Ľ��ֵ��";
	cin >> x;
	T.remove(x);
	cout << "������������";
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
	cout << "������ƽ��������Ľ�����У�\n";
	int x;
	while (cin >> x)
		T.insert(x);
	cin.clear();//����cin״̬��ʶ��
	rewind(stdin);//������뻺����
	cout << "������������";
	T.inOrder();
	cout << "\n------------------------------------------\n";
}
void searchAVLTree(AVLTree<int>& T) {
	int x;
	cout << "������һ�������ҵĽ��ֵ��";
	cin >> x;
	if (T.search(x))
		cout << "�ǵݹ���ҷ��ָõ㡣����\n";
	else
		cout << "�ǵݹ����δ�ҵ��õ㡣����\n";
	if (T.search_rec(x))
		cout << "�ݹ���ҷ��ָõ㡣����\n";
	else
		cout << "�ݹ����δ�ҵ��õ㡣����\n";
	cout << "\n------------------------------------------\n";
}
void insertAVLTree(AVLTree<int>& T) {
	int x;
	cout << "������һ������Ľ��ֵ��";
	cin >> x;
	T.insert(x);
	cout << "������������";
	T.inOrder();
	cout << "\n------------------------------------------\n";
}
void deleteAVLTree(AVLTree<int>& T) {
	int x;
	cout << "������һ����ɾ���Ľ��ֵ��";
	cin >> x;
	T.remove(x);
	cout << "������������";
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
	cout << "������B-���Ĺؼ��֣�\n";
	while (cin >> key)
		T.insert(key);
	cin.clear();
	rewind(stdin);
	cout << T.Order() << "��B-����" << T.Size() << "����㣺\n";
	T.print();
	cout << endl;
}
void searchB_Tree(B_Tree<int>& T) {
	int key;
	cout << "������Ҫ���ҵĹؼ��֣�";
	cin >> key;
	Result<int>result = T.search(key);
	if (result.tag)
		cout << "�ùؼ�����B-�����׹ؼ���Ϊ" << result.ptr->key[0] << "��Ӧ���ĵ�"
		<< result.pos + 1 << "��λ���ϡ�����\n";
	else
		cout << "B-����û������ؼ��֡�����\n";
}
void insertB_Tree(B_Tree<int> &T){
	int key;
	cout << "����Ҫ����B-���Ĺؼ��֣�";
	cin >> key;
	if (T.insert(key)) {
		cout << "������" << T.Order() << "��B-����" << T.Size() << "����㣺\n";
		T.print();
		cout << endl;
	}
	else
		cout << "B-�����Ѵ��ڸùؼ��֡�����\n";
}
void removeB_Tree(B_Tree<int>& T) {
	int key;
	cout << "����Ҫɾ��B-���Ĺؼ��֣�";
	cin >> key;
	if (T.insert(key)) {
		cout << "ɾ�����" << T.Order() << "��B-����" << T.Size() << "����㣺\n";
		T.print();
		cout << endl;
	}
	else
		cout << "B-���в����ڸùؼ��֡�����\n";
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
	cout << "�������ϣ��Ĺؼ��֣�\n";
	while (cin >> key)
		H.insert(key);
	cin.clear();
	rewind(stdin);
	cout << "�����Ĺ�ϣ��Ϊ��\n";
	H.print();
}
void searchHashTable(HashTable<int>& H) {
	do {
		int key;
		cout << "����������ҵĹؼ��֣�-1�˳�����";
		cin >> key;;
		rewind(stdin);
		if (key == -1)
			break;
		if (H.search(key))
			cout << "��ϣ������" << key << "����ؼ��ּ�¼������\n";
		else
			cout << "��ϣ����δ�ҵ�ָ��Ԫ�ء�����\n";
	} while (true);
}
void deleteHashTable(HashTable<int>& H) {
	int key;
	cout << "������Ҫɾ���Ĺؼ��֣�";
	cin >> key;
	H.remove(key);
	cout << "ɾ����Ĺ�ϣ��Ϊ��\n";
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