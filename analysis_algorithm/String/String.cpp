#include "String.h"
#include <iostream>

using namespace std;

void print_String(String& T) {
	cout << "�ַ�������" << T.size() << "���ַ���\n";
	cout << T << endl;//ͨ����Ԫ������������������
}
void get_sub(String& T) {
	int pos, len;
	cout << "���뿪ʼλ�ú��Ӵ����ȣ�\n";
	cin >> pos >> len;
	String* sub = T.substr(pos, len);
	if (!sub->empty()) {
		cout << "�ӵ�" << pos << "���ַ��𳤶�Ϊ" << len << "���Ӵ�Ϊ��\n";
		print_String(*sub);
	}
	else
		cout << "���Ӵ�ʧ��...\n";
}
int compare(String& a, String& b) {
	for (int i = 0; i < a.size() && i < b.size(); ++i) {
		if (a[i] != b[i]) {
			return (a[i] - b[i]);
		}
	}
	return (a.size() - b.size());
}

void test_4_2_4() {
	String T;
	String a("abcdef"), b("ghijk");
	cout << "�ַ���a=" << a << endl;
	cout << "�ַ���b=" << b << endl;
	T.contact(a);
	T.contact(b);
	cout << "���Ӻ���ַ���ΪT" << endl;
	print_String(T);
}
void test_4_2_3() {
	char chars[][8] = { "abcdef","abcdgf","abcdefg" };
	String s(chars[0]);
	for (int i = 0; i < 3; ++i) {
		String t(chars[i]);
		cout << "�ַ���s=" << s << " ";
		if (compare(s, t) == 0) {
			cout << "����";
		}
		else if (compare(s, t) > 0) {
			cout << "����";
		}
		else if (compare(s, t) < 0) {
			cout << "С��";
		}
		cout << " �ַ���t=" << t << endl;
	}
}
void test_4_2_2() {
	String T("data structure");
	print_String(T);
	get_sub(T);

	system("pause");
}
void test_4_2_1() {
	char chars[10] = { "abcdefgh" };
	String T(chars);
	print_String(T);
}
int main() {

	//test_4_2_1();
	//test_4_2_2();
	//test_4_2_3();
	test_4_2_4();
	return 0;
}