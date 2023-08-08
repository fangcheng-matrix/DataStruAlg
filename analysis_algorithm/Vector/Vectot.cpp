#include <iostream>
#include "Vector.h"
#include "Vector_Search.h"
using namespace std;

void creat_Vector(Vector<int>& L) {
	int sqlen;
	cout << "请输入顺序表元素个数：";
	cin >> sqlen;
	cout << "请输入顺序表元素：\n";
	for (int i = 0; i < sqlen; i++) {
		int e;
		cin >> e;
		L.insert(e);
	}
}
void insert_Vector(Vector<int>& L) {
	int location, element;
	cout << "请输入插入位置：";
	cin >> location;
	while (location > L.size() + 1 || location < 1) {
		cout << "输入位置错误，请重新输入！\n";
		cin >> location;
	}
	cout << "请输入插入元素：";
	cin >> element;
	L.insert(location - 1, element);
	cout << "插入完成！";
}
void print_Vector(Vector<int>& L) {
	cout << "顺序表一共有" << L.size() << "个元素：\n";
	for (int i = 0; i < L.size(); ++i) {
		cout<<L[i]<<" ";
	}
	cout << endl;
}
//查找顺序表中元素
void find_Vector(Vector<int>& L) {
	int location;
	cout << "请输入查找的位置：";
	cin >> location;
	while (location > L.size() || location < 1) {
		cout << "输入位置错误，请重新输入：";
		cin >> location;
	}
	cout << "第" << location << "个元素是：" << L.get_elem(location) << endl;

	int element;
	cout << "请输入查找的元素：";
	cin >> element;
	if (!L.locate_elem(element))
		cout << "该顺序表中没有" << element << "这个元素！\n";
	else
		cout << element << "在顺序表中是第" << L.locate_elem(element) << "个元素\n";
}
void delete_Vector(Vector<int>& L) {
	int location;
	cout << "请输入要删除元素的位置：";
	cin >> location;
	while (location > L.size() || location < 1) {
		cout << "输入位置错误，请重新输入：\n";
		cin >> location;
	}
	cout << "被删除的元素为" << L.remove(location - 1) << endl;
}

void CreatVector(Vector<int>& L) {
	int Sqlen;
	cout << "输入顺序表元素个数：";
	cin >> Sqlen;
	cout << "请输入顺序表元素：\n";
	for (int i = 0; i < Sqlen; i++) {
		int e;
		cin >> e;
		L.insert(e);
	}
}
void PrintVector(Vector<int>& L) {
	cout << "顺序表一共" << L.size() << "个元素：\n";
	for (int i = 0; i < L.size(); i++)
		cout << L[i] << ' ';
	cout << endl;
}
void SearchVector(Vector<int>& L) {
	do {
		int key, pos;
		cout << "请输入待查找的关键字（-1退出）:";
		cin >> key;
		rewind(stdin);
		if (key == -1)
			break;
		if ((pos = L.seqSearch_rec(key)) != -1)
			cout << "递归查找发现，" << key << "在线性表的第" << pos << "个位置。。。\n";
		else
			cout << "未找到指定元素。。。\n";
		if ((pos = L.seqSearch(key)) != -1)
			cout << "非递归查找发现，" << key << "在线性表的第" << pos << "个位置。。。\n";
		else
			cout << "未找到指定元素。。。\n";
	} while (true);
}

void test01() {
	Vector<int> L;
	CreatVector(L);
	PrintVector(L);
	SearchVector(L);
}

void test_2_2_1() {
	Vector<int> L;
	creat_Vector(L);
	print_Vector(L);
	insert_Vector(L);
	print_Vector(L);
}
void test_2_2_2() {
	Vector<int> L;
	creat_Vector(L);
	print_Vector(L);
	find_Vector(L);
}
void test_2_2_3() {
	Vector<int> L;
	creat_Vector(L);
	print_Vector(L);
	delete_Vector(L);
	print_Vector(L);
}

int main() {
	//test_2_2_1();
	//test_2_2_2();
	//test_2_2_3();
	test01();
	return 0;
}