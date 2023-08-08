#include<iostream>
#include"Generalized_List.h"
using namespace std;

void print_GLNode(GLNode<char>* p) {
	//为空表时只有括号
	if (p->ptr.hp == NULL)
		cout << "( )";
	else if (p->ptr.hp->tag == 0)
		cout << p->ptr.hp->data;
	//为非空广义表时递归输出
	else {
		cout << "(";
		print_GLNode(p->ptr.hp);
		cout << ")";
	}
	//后继为空则返回，否则添加逗号递归输出
	if (p->ptr.tp == NULL)
		return;
	cout << ",";
	print_GLNode(p->ptr.tp);
}
//递归打印广义表
void print_GList(GList<char>& GL) {
	cout << "长度为" << GL.length() << "的广义表：(";
	print_GLNode(GL.header());
	cout << ")" << endl;
	cout << "该广义表深度为：" << GL.depth() << endl;
}
void create_GList(GList<char>& GL) {
	char s[100];
	cout << "输入广义表的书写形式串S,例如S=(a,(b,(c,d))):\nS=";
	cin >> s;
	if (GL.create(s))
		cout << "创建广义表成功..." << endl;
	else
		cout << "创建广义表失败..." << endl;
}

int main() {
	GList<char> GL;
	create_GList(GL);
	print_GList(GL);

	return 0;
}