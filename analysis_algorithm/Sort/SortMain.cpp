#include "../Vector/Vector.h"
#include "../Vector/Vector_sort.h"
#include "RadixSort.h"
#include <iostream>
using namespace std;

void CreateVector(Vector<int>& L) {
	int e;
	cout << "请输入顺序表元素：\n";
	while (cin >> e)
		L.insert(e);
	cin.clear();
	rewind(stdin);
}
void PrintVector(Vector<int>& L) {
	cout << "顺序表一共" << L.size() << "个元素：\n";
	for (int i = 0; i < L.size(); i++)
		cout << L[i] << ' ';
	cout << endl;
}

void testStrInsert() {
	Vector<int> L;
	CreateVector(L);
	PrintVector(L);
	L.insertSort();
	cout << "\n顺序表进行插入排序后，结果为：\n";
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
	cout << "\n顺序表进行希尔排序后结果为：\n";
	PrintVector(L);
}
void testQuick() {
	Vector<int> L;
	CreateVector(L);
	PrintVector(L);
	L.quickSort();
	cout << "\n顺序表进行快速排序后结果为：\n";
	PrintVector(L);
}
void testSelect() {
	Vector<int> L;
	CreateVector(L);
	PrintVector(L);
	L.selectSort();
	cout << "\n顺序表进行选择排序后结果为：\n";
	PrintVector(L);
}
void testHeap() {
	Vector<int> L;
	CreateVector(L);
	PrintVector(L);
	L.heapSort();
	cout << "\n顺序表进行堆排序后结果为：\n";
	PrintVector(L);
}
/*void testMerge() {
	Vector<int> L;
	CreateVector(L);
	PrintVector(L);
	L.mergeSort();
	cout << "\n顺序表进行归并排序后结果为：\n";
	PrintVector(L);
}*/
void testRadix() {
	Vector<int> V;
	int max = CreateVector0(V);
	PrintVector0(V);
	int keynum = getKeynum(max);
	radixSort(V, keynum);
	cout << "\n顺序表进行基数排序后结果为：\n";
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