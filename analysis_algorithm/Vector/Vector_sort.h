#pragma once
#ifndef _VECTOR_SORT_H_
#define _VECTOR_SORT_H_
#include "../Sort/Heap.h"
#include "Vector.h"
#include <iostream>

//��[low,high]�����е�Ԫ����dk������в�������
template<typename T>
void Vector<T>::insertSort(int low, int high, int dk) {
	if (low<0 || high>=length || low >= high || dk <= 0)
		return;
	for (int i = low + dk; i <= high; i++) {
		T tmp = elem[i];
		int j = i - dk;
		//��i��ǰһ��Ԫ�ؿ�ʼ���ڱ�Ԫ�رȽϲ��ƶ�Ԫ��
		while (tmp < elem[j] && j >= low) {
			elem[j + dk] = elem[j];
			j -= dk;
		}
		elem[j + dk] = tmp;
		/*std::cout << "��ǰ������Ϊ��";
		for (int k = 0; k < length; k++)
			std::cout << elem[k] << ' ';
		std::cout << std::endl;*/
	}
}

template<typename T>
void Vector<T>::shellSort(Vector<int>& dlta) {
	for (int k = 0; k < dlta.size(); k++) {
		insertSort(0, length - 1, dlta[k]);
		std::cout << "��" << k + 1 << "��������Ϊ��";
		for (int k = 0; k < length; k++)
			std::cout << elem[k] << ' ';
		std::cout << std::endl;
	}
}

template<typename T>
int Vector<T>::partition(int low, int high) {
	//������Ԫ��ֵ
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
	std::cout << "��ǰ������Ϊ��";
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
		//�ҵ�����Ԫ������С��Ԫ�ؼ�¼Ϊpos
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
	std::cout << "��ʼ���н��ɵĴ󶥶�Ϊ��";
	for (int k = 0; k < length; k++)
		std::cout << H[k] << ' ';
	std::cout << std::endl;
	while (!H.empty()) {
		elem[high--] = H.pop();
		std::cout << "����Ԫ��Ϊ��" << elem[high + 1];
		std::cout << "\t��ǰ�󶥶�Ϊ��";
		for (int k = 0; k < H.size(); k++)
			std::cout << H[k] << ' ';
		std::cout << std::endl;
	}
}

template<typename T>
void Vector<T>::merge(int low, int mid, int high) {
	//��ʱ�������ڴ洢�ϲ����
	T* tmp = new T[high - low + 1];
	//�ֱ������ʱ���飬[low,mid]�͡�mid+1,high]
	int t = 0, i = low, j = mid + 1;
	while (i < mid && j <= high) {
		if (elem[i] <= elem[j])
			tmp[t++] = elem[i++];
		else
			tmp[t++] = elem[j++];
	}
	//��ʣ��Ԫ�ط���tmp
	while (i <= mid)
		tmp[t++] = elem[i++];
	while (j <= high)
		tmp[t++] = elem[j++];
	//��tmp�еĽ�����Ƶ�ԭ˳���
	while (high >= low)
		elem[high--] = tmp[--t];
	delete[]tmp;
	std::cout << "��ǰ�ϲ���������Ϊ��";
	for (int k = 0; k < length; k++)
		std::cout << elem[k] << ' ';
	std::cout << std::endl;
}
#endif // _VECTOR_SORT_H_
