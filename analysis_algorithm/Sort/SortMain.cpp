#include "../Vector/Vector.h"
#include "../Vector/Vector_sort.h"
#include "RadixSort.h"
#include <iostream>
using namespace std;

void CreateVector(Vector<int>& L) {
	int e;
	cout << "������˳���Ԫ�أ�\n";
	while (cin >> e)
		L.insert(e);
	cin.clear();
	rewind(stdin);
}
void PrintVector(Vector<int>& L) {
	cout << "˳���һ��" << L.size() << "��Ԫ�أ�\n";
	for (int i = 0; i < L.size(); i++)
		cout << L[i] << ' ';
	cout << endl;
}

void testStrInsert() {
	Vector<int> L;
	CreateVector(L);
	PrintVector(L);
	L.insertSort();
	cout << "\n˳�����в�������󣬽��Ϊ��\n";
	PrintVector(L);
}
void testShell() {
	Vector<int> L;
	CreateVector(L);
	PrintVector(L);
	Vector<int> dlta(4);
	dlta.insert(8);
	dlta.insert(4);
	dlta.insert(2);
	dlta.insert(1);
	L.shellSort(dlta);
	cout << "\n˳������ϣ���������Ϊ��\n";
	PrintVector(L);
}
void testQuick() {
	Vector<int> L;
	CreateVector(L);
	PrintVector(L);
	L.quickSort();
	cout << "\n˳�����п����������Ϊ��\n";
	PrintVector(L);
}
void testSelect() {
	Vector<int> L;
	CreateVector(L);
	PrintVector(L);
	L.selectSort();
	cout << "\n˳������ѡ���������Ϊ��\n";
	PrintVector(L);
}
void testHeap() {
	Vector<int> L;
	CreateVector(L);
	PrintVector(L);
	L.heapSort();
	cout << "\n˳�����ж��������Ϊ��\n";
	PrintVector(L);
}
/*void testMerge() {
	Vector<int> L;
	CreateVector(L);
	PrintVector(L);
	L.mergeSort();
	cout << "\n˳�����й鲢�������Ϊ��\n";
	PrintVector(L);
}*/
void testRadix() {
	Vector<int> V;
	int max = CreateVector0(V);
	PrintVector0(V);
	int keynum = getKeynum(max);
	radixSort(V, keynum);
	cout << "\n˳�����л����������Ϊ��\n";
	PrintVector0(V);
}

int main() {
	//testStrInsert();
	//testShell();
	//testQuick();
	//testSelect();
	testHeap();
	//testMerge();
}