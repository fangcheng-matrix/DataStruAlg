#include "../Queue/Queue.h"
#include "../Vector/Vector.h"
#include <iostream>
using namespace std;

#define RADIX 10 //基数为10，处理十进制数

int CreateVector0(Vector<int>& L) {
	int e, max = 0;
	cout << "请输入顺序表元素：\n";
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
	cout << "顺序表一共有" << L.size() << "个元素：\n";
	for (int i = 0; i < L.size(); i++)
		cout << L[i] << ' ';
	cout << endl;
}
//通过最大值计算关键字项数
int getKeynum(int maxElem) {
	int i;
	for (i = 0; maxElem; i++)
		maxElem /= RADIX;
	return i;
}
//计算元素x的pos位关键字
int ord(int x, int pos) {
	for (int i = 0; i < pos; i++)
		x /= 10;
	return x % 10;
}
//按第i位关键字分配给对应的队列
void distribute(Vector<int>& L, int i, Queue<int>* Q) {
	for (int j = 0; j < L.size(); j++) {
		int k = ord(L[j], i);
		Q[k].enqueue(L[j]);
	}
}
//按顺序进行收集
void collect(Vector<int>& L, Queue<int>* Q) {
	int j = 0;
	for (int i = 0; i < RADIX; i++)
		while (!Q[i].empty())
			L[j++] = Q[i].dequeue();
}
//对顺序表L进行关键字项数位keynum的基数排序
void radixSort(Vector<int>& L, int keynum) {
	Queue<int>* Q = new Queue<int>[RADIX];
	for (int i = 0; i < keynum; i++) {
		distribute(L, i, Q);
		collect(L, Q);
		cout << "第" << i + 1 << "趟收集结果为：";
		PrintVector0(L);
	}
}