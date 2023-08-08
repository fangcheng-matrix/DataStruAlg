#include "../Queue/Queue.h"
#include "../Vector/Vector.h"
#include <iostream>
using namespace std;

#define RADIX 10 //����Ϊ10������ʮ������

int CreateVector0(Vector<int>& L) {
	int e, max = 0;
	cout << "������˳���Ԫ�أ�\n";
	while (cin >> e) {
		L.insert(e);
		if (max < e)
			max = e;
	}
	cin.clear();
	rewind(stdin);
	return max;
}
void PrintVector0(Vector<int>& L) {
	cout << "˳���һ����" << L.size() << "��Ԫ�أ�\n";
	for (int i = 0; i < L.size(); i++)
		cout << L[i] << ' ';
	cout << endl;
}
//ͨ�����ֵ����ؼ�������
int getKeynum(int maxElem) {
	int i;
	for (i = 0; maxElem; i++)
		maxElem /= RADIX;
	return i;
}
//����Ԫ��x��posλ�ؼ���
int ord(int x, int pos) {
	for (int i = 0; i < pos; i++)
		x /= 10;
	return x % 10;
}
//����iλ�ؼ��ַ������Ӧ�Ķ���
void distribute(Vector<int>& L, int i, Queue<int>* Q) {
	for (int j = 0; j < L.size(); j++) {
		int k = ord(L[j], i);
		Q[k].enqueue(L[j]);
	}
}
//��˳������ռ�
void collect(Vector<int>& L, Queue<int>* Q) {
	int j = 0;
	for (int i = 0; i < RADIX; i++)
		while (!Q[i].empty())
			L[j++] = Q[i].dequeue();
}
//��˳���L���йؼ�������λkeynum�Ļ�������
void radixSort(Vector<int>& L, int keynum) {
	Queue<int>* Q = new Queue<int>[RADIX];
	for (int i = 0; i < keynum; i++) {
		distribute(L, i, Q);
		collect(L, Q);
		cout << "��" << i + 1 << "���ռ����Ϊ��";
		PrintVector0(L);
	}
}