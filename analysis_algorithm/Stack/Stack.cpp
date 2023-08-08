#include <iostream>
#include "Stack.h"

using namespace std;

void create_Stack(Stack<int>& s) {
	int e;
	cout << "请输入数据：\n";
	while (cin >> e) {
		s.push(e);
	}
	cin.clear();
	rewind(stdin);
}
void print_Stack(Stack<int>& s) {
	cout << "清空并输出，栈内共有" << s.size() << "个元素：\n";
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