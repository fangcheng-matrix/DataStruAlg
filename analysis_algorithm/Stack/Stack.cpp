#include <iostream>
#include "Stack.h"

using namespace std;

void create_Stack(Stack<int>& s) {
	int e;
	cout << "���������ݣ�\n";
	while (cin >> e) {
		s.push(e);
	}
	cin.clear();
	rewind(stdin);
}
void print_Stack(Stack<int>& s) {
	cout << "��ղ������ջ�ڹ���" << s.size() << "��Ԫ�أ�\n";
	while (!s.empty())
		cout << s.pop() << ' ';
	cout << endl;
}

void test01() {
	Stack<int> stk;
	create_Stack(stk);
	print_Stack(stk);
}

int main() {
	test01();

	return 0;
}