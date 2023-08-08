#include<iostream>
#include"../List/List.h"
using namespace std;

//����洢����ʽ�Ľ��
struct Mono {
	double coef;
	int exp;
};

//�Ե�����Ϊģ��������һԪ����ʽ�������
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
			//�ж�ָ���Ƿ���ȣ��������ϵ����Ӳ��ϲ����µ�һ��
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
			//��paָ����С��������Lc����pa
			else if (pa->data.exp < pb->data.exp) {
				pc->next = pa;
				pc = pa;
				pa = pa->next;
			}
			//��pbָ����С��������Lc����pb
			else
			{
				pc->next = pb;
				pc = pb;
				pb = pb->next;
			}
		}
		//����δ������ı�ʣ�����Lc��
		pc->next = pa ? pa : pb;
		_size = La.size() + Lb.size() + tmp;
		La.init();
		Lb.init();
	}
};
//����һԪ����ʽ
void creat_poly(Poly& L) {
	double c;
	int index;
	//����һԪ����ʽ����ϵ����ָ������ͷ�巨����������
	while (cin >> c >> index) {
		Mono m_Mono{c, index};
		L.insert(m_Mono);
	}
	cin.clear();
	rewind(stdin);
}
//��ӡһԪ����ʽ
void print_poly(Poly& L) {
	cout << "����" << L.size() << "�";
	for (LNode<Mono>* p = L.head(); p; p = p->next) {
		if (p->data.coef != 0) {
			if (p->data.coef > 0) cout << "+";
			if (!p->data.exp) cout << p->data.coef;//�����Ϊ����
			else if (p->data.exp == 1) cout << p->data.coef << "x";//�����Ϊһ����
			else cout << p->data.coef << "x^" << p->data.exp;//������ݴδ���1
		}
	}
	cout << endl;
}

int main() {
	Poly La, Lb, Lc;
	cout << "�밴�ݴν��������һ��һԪ����ʽ�ĸ���ϵ�����ݴΣ�\n";
	creat_poly(La);
	cout << "�밴�ݴν�������ڶ���һԪ����ʽ�ĸ���ϵ�����ݴΣ�\n";
	creat_poly(Lb);
	cout << "һԪ����ʽLaΪ��\n";
	print_poly(La);
	cout << "һԪ����ʽLbΪ��\n";
	print_poly(Lb);
	Lc.merge_poly(La, Lb);
	cout << "La��Lb��Ӻ��һԪ����ʽLcΪ��\n";
	print_poly(Lc);

	return 0;
}