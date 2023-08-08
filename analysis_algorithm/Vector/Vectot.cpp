#include <iostream>
#include "Vector.h"
#include "Vector_Search.h"
using namespace std;

void creat_Vector(Vector<int>& L) {
	int sqlen;
	cout << "������˳���Ԫ�ظ�����";
	cin >> sqlen;
	cout << "������˳���Ԫ�أ�\n";
	for (int i = 0; i < sqlen; i++) {
		int e;
		cin >> e;
		L.insert(e);
	}
}
void insert_Vector(Vector<int>& L) {
	int location, element;
	cout << "���������λ�ã�";
	cin >> location;
	while (location > L.size() + 1 || location < 1) {
		cout << "����λ�ô������������룡\n";
		cin >> location;
	}
	cout << "���������Ԫ�أ�";
	cin >> element;
	L.insert(location - 1, element);
	cout << "������ɣ�";
}
void print_Vector(Vector<int>& L) {
	cout << "˳���һ����" << L.size() << "��Ԫ�أ�\n";
	for (int i = 0; i < L.size(); ++i) {
		cout<<L[i]<<" ";
	}
	cout << endl;
}
//����˳�����Ԫ��
void find_Vector(Vector<int>& L) {
	int location;
	cout << "��������ҵ�λ�ã�";
	cin >> location;
	while (location > L.size() || location < 1) {
		cout << "����λ�ô������������룺";
		cin >> location;
	}
	cout << "��" << location << "��Ԫ���ǣ�" << L.get_elem(location) << endl;

	int element;
	cout << "��������ҵ�Ԫ�أ�";
	cin >> element;
	if (!L.locate_elem(element))
		cout << "��˳�����û��" << element << "���Ԫ�أ�\n";
	else
		cout << element << "��˳������ǵ�" << L.locate_elem(element) << "��Ԫ��\n";
}
void delete_Vector(Vector<int>& L) {
	int location;
	cout << "������Ҫɾ��Ԫ�ص�λ�ã�";
	cin >> location;
	while (location > L.size() || location < 1) {
		cout << "����λ�ô������������룺\n";
		cin >> location;
	}
	cout << "��ɾ����Ԫ��Ϊ" << L.remove(location - 1) << endl;
}

void CreatVector(Vector<int>& L) {
	int Sqlen;
	cout << "����˳���Ԫ�ظ�����";
	cin >> Sqlen;
	cout << "������˳���Ԫ�أ�\n";
	for (int i = 0; i < Sqlen; i++) {
		int e;
		cin >> e;
		L.insert(e);
	}
}
void PrintVector(Vector<int>& L) {
	cout << "˳���һ��" << L.size() << "��Ԫ�أ�\n";
	for (int i = 0; i < L.size(); i++)
		cout << L[i] << ' ';
	cout << endl;
}
void SearchVector(Vector<int>& L) {
	do {
		int key, pos;
		cout << "����������ҵĹؼ��֣�-1�˳���:";
		cin >> key;
		rewind(stdin);
		if (key == -1)
			break;
		if ((pos = L.seqSearch_rec(key)) != -1)
			cout << "�ݹ���ҷ��֣�" << key << "�����Ա�ĵ�" << pos << "��λ�á�����\n";
		else
			cout << "δ�ҵ�ָ��Ԫ�ء�����\n";
		if ((pos = L.seqSearch(key)) != -1)
			cout << "�ǵݹ���ҷ��֣�" << key << "�����Ա�ĵ�" << pos << "��λ�á�����\n";
		else
			cout << "δ�ҵ�ָ��Ԫ�ء�����\n";
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