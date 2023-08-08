#include<iostream>
#include"CList.h"

using namespace std;

void creat_CList(CList<int>& L) {
	cout << "��������������Ԫ�أ�������ͷ��������\n";
	int x;
	while (cin >> x) {
		L.insert(x);
	}
	cin.clear();
	rewind(stdin);
}
//����ѭ�������е�Ԫ��
void find_CList(CList<int>& L) {
	int i, e;
	cout << "������Ҫ���ҵ�Ԫ��λ��i��";
	cin >> i;
	if (L.get_node(i)) {
		cout << "��" << i << "��Ԫ�ص�ֵ�ǣ�" << L.get_node(i)->data << endl;
	}
	else {
		cout << "û�����Ԫ�أ�\n";
	}
	cout << "������Ҫ���ҵ�Ԫ��e��";
	cin >> e;
	if (L.locate_elem(e)) {
		cout << "Ԫ��" << e << "���������ǵ�" << L.locate_elem(e) << "��Ԫ��\n";
	}
	else {
		cout << "û�����Ԫ�أ�\n";
	}
}
//��Ԫ�ز���ѭ������
void insert_CList(CList<int>& L) {
	int i, e;
	cout << "������Ҫ����Ԫ�ص�λ�ã�";
	cin >> i;
	printf("������Ҫ����Ԫ�ص�ֵ��");
	cin >> e;
	LNode<int>* p = L.get_node(i - 1);
	if (!p) {
		cout << "����ʧ�ܣ�\n";
	}
	else {
		L.insert(p, e);
	}
}
//ɾ��ѭ�������е�Ԫ��
void delete_CList(CList<int>& L) {
	if (L.empty()) {
		cout << "����Ϊ�գ��޷�ɾ����\n";
		return;
	}
	int i;
	cout << "��������Ҫɾ��Ԫ�ص�λ�ã�";
	cin >> i;
	LNode<int>* p = L.get_node(i);
	if (!p) {
		cout << "ɾ��ʧ�ܣ�\n";
	}
	else {
		cout << "ɾ����Ԫ��e�ǣ�" << L.remove(p) << endl;
	}
}
//��ӡѭ�������е�Ԫ��
void print_CList(CList<int> &L) {
	if (L.empty()) {
		cout << "����Ϊ�գ�\n";
		return;
	}
	LNode<int>* p = L.head();
	cout << "������" << L.size() << "��Ԫ�أ�\n";
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