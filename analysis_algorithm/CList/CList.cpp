#include<iostream>
#include"CList.h"

using namespace std;

void creat_CList(CList<int>& L) {
	cout << "请逆序输入链表元素，建立带头结点的链表：\n";
	int x;
	while (cin >> x) {
		L.insert(x);
	}
	cin.clear();
	rewind(stdin);
}
//查找循环链表中的元素
void find_CList(CList<int>& L) {
	int i, e;
	cout << "请输入要查找的元素位置i：";
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
//将元素插入循环链表
void insert_CList(CList<int>& L) {
	int i, e;
	cout << "请输入要插入元素的位置：";
	cin >> i;
	printf("请输入要插入元素的值：");
	cin >> e;
	LNode<int>* p = L.get_node(i - 1);
	if (!p) {
		cout << "插入失败！\n";
	}
	else {
		L.insert(p, e);
	}
}
//删除循环链表中的元素
void delete_CList(CList<int>& L) {
	if (L.empty()) {
		cout << "链表为空，无法删除！\n";
		return;
	}
	int i;
	cout << "请输入需要删除元素的位置：";
	cin >> i;
	LNode<int>* p = L.get_node(i);
	if (!p) {
		cout << "删除失败！\n";
	}
	else {
		cout << "删除的元素e是：" << L.remove(p) << endl;
	}
}
//打印循环链表中的元素
void print_CList(CList<int> &L) {
	if (L.empty()) {
		cout << "链表为空！\n";
		return;
	}
	LNode<int>* p = L.head();
	cout << "链表共有" << L.size() << "个元素：\n";
	while (p->next != L.head()) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void test_2_5_1() {
	CList<int> L;
	creat_CList(L);
	print_CList(L);
	//find_CList(L);
	//insert_CList(L);
	//print_CList(L);
	delete_CList(L);
	print_CList(L);
}

int main() {
	test_2_5_1();

	system("pause");
	return 0;
}