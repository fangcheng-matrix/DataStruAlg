#include<iostream>
#include"DuList.h"

using namespace std;

//����˫������
void create_DuList(DuList<int>& L) {
	int e;
	cout << "����������Ԫ�أ�������ͷ����˫������\n";
	while (cin >> e) {
		L.insert_last(e);
	}
	cin.clear();
	rewind(stdin);
}
//��Ԫ�ز���˫������
void insert_DuList(DuList<int>& L) {
	int i, e;
	cout << "������Ҫ����Ԫ�ص�λ��i��";
	cin >> i;
	printf("������Ҫ����Ԫ�ص�ֵe��");
	cin >> e;
	DuLNode<int>* p = L.get_node(i - 1);
	if (!p)
		cout << "����ʧ�ܣ�\n";
	else {
		L.insert_after(p, e);
		cout << "����ɹ���\n";
	}
}
//��ӡ˫�������е�Ԫ��
void print_DuList(DuList<int>& L) {
	cout << "˫��������" << L.size() << "��Ԫ�أ�\n";
	for (DuLNode<int>* p = L.first(); p->prior != L.last(); p = p->next) {
		cout << p->data << " ";
	}
	cout << endl;
}
//����˫�������е�Ԫ��
void find_DuList(DuList<int>& L) {
	int i, e;
	cout << "��������ҵ�Ԫ�ص�λ��i��";
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
//ɾ��˫�������е�Ԫ��
void delete_DuList(DuList<int>& L) {
	if (L.empty()) {
		cout << "����Ϊ�գ��޷�ɾ����\n";
		return;
	}
	int i, e;
	cout << "������Ҫɾ��Ԫ�ص�λ��i��";
	cin >> i;
	DuLNode<int>* p = L.get_node(i);
	e = L.remove(p);
	if (!p) {
		cout << "ɾ��ʧ�ܣ�\n";
	}
	else {
		cout << "ɾ����Ԫ��e�ǣ�" << e << endl;
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