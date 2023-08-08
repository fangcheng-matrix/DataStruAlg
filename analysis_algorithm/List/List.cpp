#include<iostream>
#include"List.h"
using namespace std;

//����������
void creat_List(List<int>& L) {
	cout << "��������������Ԫ�أ�������ͷ��������" << endl;
	int x;
	while (cin >> x)
		L.insert(x);
	cin.clear();
	rewind(stdin);
}
//��Ԫ�ز��뵥����
void insert_List(List<int>& L) {
	int i, e;
	cout << "������Ҫ����Ԫ�ص�λ��i:";
	cin >> i;
	cout << "������Ҫ����Ԫ�ص�ֵe:";
	cin >> e;
	LNode<int>* p = L.get_node(i - 1);
	if (!p)
		cout << "����ʧ�ܣ�\n";
	else {
		L.insert(p, e);
		cout<<"����ɹ���\n";
	}
}
//��ӡ�������е�Ԫ��
void print_List(List<int>& L) {
	if (L.empty()) {
		cout << "������Ϊ�գ�\n";
		return;
	}
	LNode<int>* p = L.head();
	cout << "��������" << L.size() << "��Ԫ�أ�\n";
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
//����
void find_List(List<int>& L) {
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
		cout << "Ԫ��" << e << "�ڵ��������ǵ�" << L.locate_elem(e) << "��Ԫ��\n";
	}
	else {
		cout << "û�����Ԫ�أ�\n";
	}
}
//ɾ��
void delete_List(List<int>& L) {
	if (L.empty()) {
		cout << "����Ϊ�գ��޷�ɾ����\n";
		return;
	}
	
	int i, e;
	cout << "������Ҫɾ��Ԫ�ص�λ�ã�";
	cin >> i;
	LNode<int>* p = L.get_node(i);
	if (!p) {
		cout << "ɾ��ʧ�ܣ�\n";
	}
	else {
		cout << "ɾ����Ԫ��e�ǣ�" << L.remove(p) << endl;
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
	cout << "������LaΪ��\n";
	print_List(La);
	cout << "������LbΪ��\n";
	print_List(Lb);

	La.merge(Lb);
	cout << "�ϲ���ĵ�����LcΪ��\n";
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