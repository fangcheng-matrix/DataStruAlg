#include "String.h"
#include <iostream>

using namespace std;

void print_String(String& T) {
	cout << "字符串共有" << T.size() << "个字符：\n";
	cout << T << endl;//通过友元函数重载了输出运算符
}
void get_sub(String& T) {
	int pos, len;
	cout << "输入开始位置和子串长度：\n";
	cin >> pos >> len;
	String* sub = T.substr(pos, len);
	if (!sub->empty()) {
		cout << "从第" << pos << "个字符起长度为" << len << "的子串为：\n";
		print_String(*sub);
	}
	else
		cout << "求子串失败...\n";
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
	cout << "字符串a=" << a << endl;
	cout << "字符串b=" << b << endl;
	T.contact(a);
	T.contact(b);
	cout << "连接后的字符串为T" << endl;
	print_String(T);
}
void test_4_2_3() {
	char chars[][8] = { "abcdef","abcdgf","abcdefg" };
	String s(chars[0]);
	for (int i = 0; i < 3; ++i) {
		String t(chars[i]);
		cout << "字符串s=" << s << " ";
		if (compare(s, t) == 0) {
			cout << "等于";
		}
		else if (compare(s, t) > 0) {
			cout << "大于";
		}
		else if (compare(s, t) < 0) {
			cout << "小于";
		}
		cout << " 字符串t=" << t << endl;
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