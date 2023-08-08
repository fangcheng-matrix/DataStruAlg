#include<iostream>
#include"List.h"
using namespace std;

//创建单链表
void creat_List(List<int>& L) {
	cout << "请逆序输入链表元素，建立带头结点的链表：" << endl;
	int x;
	while (cin >> x)
		L.insert(x);
	cin.clear();
	rewind(stdin);
}
//将元素插入单链表
void insert_List(List<int>& L) {
	int i, e;
	cout << "请输入要插入元素的位置i:";
	cin >> i;
	cout << "请输入要插入元素的值e:";
	cin >> e;
	LNode<int>* p = L.get_node(i - 1);
	if (!p)
		cout << "插入失败！\n";
	else {
		L.insert(p, e);
		cout<<"插入成功！\n";
	}
}
//打印单链表中的元素
void print_List(List<int>& L) {
	if (L.empty()) {
		cout << "单链表为空！\n";
		return;
	}
	LNode<int>* p = L.head();
	cout << "单链表共有" << L.size() << "个元素：\n";
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
//查找
void find_List(List<int>& L) {
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
		cout << "元素" << e << "在单链表中是第" << L.locate_elem(e) << "个元素\n";
	}
	else {
		cout << "没有这个元素！\n";
	}
}
//删除
void delete_List(List<int>& L) {
	if (L.empty()) {
		cout << "链表为空，无法删除！\n";
		return;
	}
	
	int i, e;
	cout << "请输入要删除元素的位置：";
	cin >> i;
	LNode<int>* p = L.get_node(i);
	if (!p) {
		cout << "删除失败！\n";
	}
	else {
		cout << "删除的元素e是：" << L.remove(p) << endl;
	}
}

void test_2_3_2() {
	List<int> L;
	creat_List(L);
	print_List(L);
	insert_List(L);
	print_List(L);
}
void test_2_3_3() {
	List<int> L;
	creat_List(L);
	print_List(L);
	find_List(L);
}
void test_2_3_4() {
	List<int> L;
	creat_List(L);
	print_List(L);
	delete_List(L);
	print_List(L);
}
void test_2_3_5() {
	List<int> La, Lb, Lc;
	creat_List(La);
	creat_List(Lb);
	cout << "单链表La为：\n";
	print_List(La);
	cout << "单链表Lb为：\n";
	print_List(Lb);

	La.merge(Lb);
	cout << "合并后的单链表Lc为：\n";
	print_List(La);
}

int main() {
	test_2_3_2();
	//test_2_3_3();
	//test_2_3_4();
	//test_2_3_5();

	system("pause");
	return 0;
}