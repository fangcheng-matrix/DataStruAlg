#pragma once
#ifndef _VECTOR_SORT_H_
#define _VECTOR_SORT_H_
#include "../Sort/Heap.h"
#include "Vector.h"
#include <iostream>

//对[low,high]区间中的元素以dk间隔进行插入排序
template<typename T>
void Vector<T>::insertSort(int low, int high, int dk) {
	if (low<0 || high>=length || low >= high || dk <= 0)
		return;
	for (int i = low + dk; i <= high; i++) {
		T tmp = elem[i];
		int j = i - dk;
		//从i的前一个元素开始与哨兵元素比较并移动元素
		while (tmp < elem[j] && j >= low) {
			elem[j + dk] = elem[j];
			j -= dk;
		}
		elem[j + dk] = tmp;
		/*std::cout << "当前排序结果为：";
		for (int k = 0; k < length; k++)
			std::cout << elem[k] << ' ';
		std::cout << std::endl;*/
	}
}

template<typename T>
void Vector<T>::shellSort(Vector<int>& dlta) {
	for (int k = 0; k < dlta.size(); k++) {
		insertSort(0, length - 1, dlta[k]);
		std::cout << "第" << k + 1 << "趟排序结果为：";
		for (int k = 0; k < length; k++)
			std::cout << elem[k] << ' ';
		std::cout << std::endl;
	}
}

template<typename T>
int Vector<T>::partition(int low, int high) {
	//保存首元素值
	T pivotkey = elem[low];
	while (low < high) {
		while (low < high && elem[high] >= pivotkey) {
			--high;
		}
		elem[low] = elem[high];
		while (low < high && elem[low] <= pivotkey) {
			++low;
		}
		elem[high] = elem[low];
	}
	elem[low] = pivotkey;
	std::cout << "当前排序结果为：";
	for (int k = 0; k < length; k++)
		std::cout << elem[k] << ' ';
	std::cout << std::endl;
	return low;
}
template<typename T>
void Vector<T>::quickSort(int low, int high) {
	if (low < 0 || high >= length || low >= high)
		return;
	int pivotloc = partition(low, high);
	quickSort(low, pivotloc - 1);
	quickSort(pivotloc + 1, high);
}

template<typename T>
void Vector<T>::selectSort(int low, int high) {
	if (low<0 || high >= length || low>+high)
		return;
	for (int i = low; i < high; i++) {
		int pos = i;
		//找到后续元素中最小的元素记录为pos
		for (int j = i + 1; j <= high; j++)
			if (elem[j] < elem[pos])
				pos = j;
		if (pos != i) {
			T tmp = elem[i];
			elem[i] = elem[pos];
			elem[pos] = tmp;
		}
	}
}

template<typename T>
void Vector<T>::heapSort(int low, int high) {
	if (low<0 || high >= length || low>+high)
		return;
	MaxHeap<T> H(elem + low, high - low + 1);
	std::cout << "初始序列建成的大顶堆为：";
	for (int k = 0; k < length; k++)
		std::cout << H[k] << ' ';
	std::cout << std::endl;
	while (!H.empty()) {
		elem[high--] = H.pop();
		std::cout << "弹出元素为：" << elem[high + 1];
		std::cout << "\t当前大顶堆为：";
		for (int k = 0; k < H.size(); k++)
			std::cout << H[k] << ' ';
		std::cout << std::endl;
	}
}

template<typename T>
void Vector<T>::merge(int low, int mid, int high) {
	//临时数组用于存储合并结果
	T* tmp = new T[high - low + 1];
	//分别遍历临时数组，[low,mid]和【mid+1,high]
	int t = 0, i = low, j = mid + 1;
	while (i < mid && j <= high) {
		if (elem[i] <= elem[j])
			tmp[t++] = elem[i++];
		else
			tmp[t++] = elem[j++];
	}
	//将剩余元素放入tmp
	while (i <= mid)
		tmp[t++] = elem[i++];
	while (j <= high)
		tmp[t++] = elem[j++];
	//将tmp中的结果复制到原顺序表
	while (high >= low)
		elem[high--] = tmp[--t];
	delete[]tmp;
	std::cout << "当前合并后排序结果为：";
	for (int k = 0; k < length; k++)
		std::cout << elem[k] << ' ';
	std::cout << std::endl;
}
#endif // _VECTOR_SORT_H_
