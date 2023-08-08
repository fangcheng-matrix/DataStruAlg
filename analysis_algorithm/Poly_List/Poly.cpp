#include<iostream>
#include"../List/List.h"
using namespace std;

//定义存储单项式的结点
struct Mono {
	double coef;
	int exp;
};

//以单链表为模板派生出一元多项式的类对象
class Poly :public List<Mono> {
public:
	void merge_poly(Poly& La, Poly& Lb) {
		init();
		int tmp = 0;
		LNode<Mono>* pa, * pb, * pc;
		pa = La.head();
		pb = Lb.head();
		pc = header;
		while (pa && pb) {
			//判断指数是否相等，相等则令系数相加并合并成新的一项
			if (pa->data.exp == pb->data.exp) {
				pa->data.coef += pa->data.coef;
				if (pa->data.coef) {
					pc->next = pa;
					pc = pa;
					tmp++;
				}
				pa = pa->next;
				pb = pb->next;
				tmp -= 2;
			}
			//若pa指数较小，则先向Lc插入pa
			else if (pa->data.exp < pb->data.exp) {
				pc->next = pa;
				pc = pa;
				pa = pa->next;
			}
			//若pb指数较小，则先向Lc插入pb
			else
			{
				pc->next = pb;
				pc = pb;
				pb = pb->next;
			}
		}
		//将尚未遍历完的表剩余项并入Lc中
		pc->next = pa ? pa : pb;
		_size = La.size() + Lb.size() + tmp;
		La.init();
		Lb.init();
	}
};
//创建一元多项式
void creat_poly(Poly& L) {
	double c;
	int index;
	//输入一元多项式各项系数和指数，用头插法存入链表中
	while (cin >> c >> index) {
		Mono m_Mono{c, index};
		L.insert(m_Mono);
	}
	cin.clear();
	rewind(stdin);
}
//打印一元多项式
void print_poly(Poly& L) {
	cout << "共有" << L.size() << "项：";
	for (LNode<Mono>* p = L.head(); p; p = p->next) {
		if (p->data.coef != 0) {
			if (p->data.coef > 0) cout << "+";
			if (!p->data.exp) cout << p->data.coef;//输出项为常数
			else if (p->data.exp == 1) cout << p->data.coef << "x";//输出项为一次项
			else cout << p->data.coef << "x^" << p->data.exp;//输出项幂次大于1
		}
	}
	cout << endl;
}

int main() {
	Poly La, Lb, Lc;
	cout << "请按幂次降序输入第一个一元多项式的各项系数与幂次：\n";
	creat_poly(La);
	cout << "请按幂次降序输入第二个一元多项式的各项系数与幂次：\n";
	creat_poly(Lb);
	cout << "一元多项式La为：\n";
	print_poly(La);
	cout << "一元多项式Lb为：\n";
	print_poly(Lb);
	Lc.merge_poly(La, Lb);
	cout << "La和Lb相加后的一元多项式Lc为：\n";
	print_poly(Lc);

	return 0;
}