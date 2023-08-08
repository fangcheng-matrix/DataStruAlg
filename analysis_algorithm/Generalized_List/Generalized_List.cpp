#include<iostream>
#include"Generalized_List.h"
using namespace std;

void print_GLNode(GLNode<char>* p) {
	//Ϊ�ձ�ʱֻ������
	if (p->ptr.hp == NULL)
		cout << "( )";
	else if (p->ptr.hp->tag == 0)
		cout << p->ptr.hp->data;
	//Ϊ�ǿչ����ʱ�ݹ����
	else {
		cout << "(";
		print_GLNode(p->ptr.hp);
		cout << ")";
	}
	//���Ϊ���򷵻أ�������Ӷ��ŵݹ����
	if (p->ptr.tp == NULL)
		return;
	cout << ",";
	print_GLNode(p->ptr.tp);
}
//�ݹ��ӡ�����
void print_GList(GList<char>& GL) {
	cout << "����Ϊ" << GL.length() << "�Ĺ����(";
	print_GLNode(GL.header());
	cout << ")" << endl;
	cout << "�ù�������Ϊ��" << GL.depth() << endl;
}
void create_GList(GList<char>& GL) {
	char s[100];
	cout << "�����������д��ʽ��S,����S=(a,(b,(c,d))):\nS=";
	cin >> s;
	if (GL.create(s))
		cout << "���������ɹ�..." << endl;
	else
		cout << "���������ʧ��..." << endl;
}

int main() {
	GList<char> GL;
	create_GList(GL);
	print_GList(GL);

	return 0;
}