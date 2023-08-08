#include<iostream>
#include"DuList.h"

using namespace std;

//创建双向链表
void create_DuList(DuList<int>& L) {
	int e;
	cout << "请输入链表元素，建立带头结点的双向链表：\n";
	while (cin >> e) {
		L.insert_last(e);
	}
	cin.clear();
	rewind(stdin);
}
//将元素插入双向链表
void insert_DuList(DuList<int>& L) {
	int i, e;
	cout << "请输入要插入元素的位置i：";
	cin >> i;
	printf("请输入要插入元素的值e：");
	cin >> e;
	DuLNode<int>* p = L.get_node(i - 1);
	if (!p)
		cout << "插入失败！\n";
	else {
		L.insert_after(p, e);
		cout << "插入成功！\n";
	}
}
//打印双向链表中的元素
void print_DuList(DuList<int>& L) {
	cout << "双向链表共有" << L.size() << "个元素：\n";
	for (DuLNode<int>* p = L.first(); p->prior != L.last(); p = p->next) {
		cout << p->data << " ";
	}
	cout << endl;
}
//查找双向链表中的元素
void find_DuList(DuList<int>& L) {
	int i, e;
	cout << "请输入查找的元素的位置i：";
	cin >> i;
	if (L.get_node(i)) {
		cout << "第" << i << "个元素的值是：" << L.get_node(i)->data << endl;
	}
	else {
		cout << "没有这个元素！\n";
	}
	cout << "请输入要查找的元素e：";
	cin >> e;
	if (L.locate_elem(e)) {
		cout << "元素" << e << "在链表中是第" << L.locate_elem(e) << "个元素\n";
	}
	else {
		cout << "没有这个元素！\n";
	}
}
//删除双向链表中的元素
void delete_DuList(DuList<int>& L) {
	if (L.empty()) {
		cout << "链表为空，无法删除！\n";
		return;
	}
	int i, e;
	cout << "请输入要删除元素的位置i：";
	cin >> i;
	DuLNode<int>* p = L.get_node(i);
	e = L.remove(p);
	if (!p) {
		cout << "删除失败！\n";
	}
	else {
		cout << "删除的元素e是：" << e << endl;
	}
}

void test_2_4_2() {
	DuList<int> L;
	create_DuList(L);
	system("pause");
	print_DuList(L);
	system("pause");
	insert_DuList(L);
	system("pause");
	print_DuList(L);
	system("pause");
}
void test_2_4_3() {
	DuList<int> L;
	create_DuList(L);
	system("pause");
	print_DuList(L);
	system("pause");
	find_DuList(L);
	system("pause");
}
void test_2_4_4() {
	DuList<int> L;
	create_DuList(L);
	system("pause");
	print_DuList(L);
	system("pause");
	delete_DuList(L);
	system("pause");
	print_DuList(L);
	system("pause");
}
int main() {
	//test_2_4_2();
	//test_2_4_3();
	test_2_4_4();
	return 0;
}