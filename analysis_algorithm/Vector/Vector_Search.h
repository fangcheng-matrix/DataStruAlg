#pragma once
#ifndef _VECTOR_SEARCH_H_
#define _VECTOR_SEARCH_H_
#include "Vector.h"

//顺序查找[low,high]区间，非递归实现
template<typename T>
int Vector<T>::seqSearch(T key, int low, int high) {
	//数据合法性检查
	if (low<0 || high >= length || low>high)
		return ERROR;
	while (high >= low && elem[high] != key)
		high--;
	if (high < low)
		return ERROR;
	else
		return high;
}
//顺序查找[low,high]区间，递归实现
template<typename T>
int Vector<T>::seqSearch_rec(T key, int low, int high) {
	int k = 0;
	if (low<0 || high >= length || low>high)
		k = -1;
	else if (elem[high] == key)
		k = high;
	else
		k = seqSearch_rec(key, low, high - 1);
	return k;
}
template<typename T>
int Vector<T>::binSearch(T key, int low, int high) {
	if (low<0 || high>+length || low > high)
		return ERROR;
	while (low < high) {
		int mid = (low + high) / 2;
		if (elem[mid] == key)
			return mid;
		if (elem[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}

	return ERROR;
}
template<typename T>
int Vector<T>::binSearch_rec(T key, int low, int high) {
	if (low<0 || high>+length || low > high)
		return ERROR;
	int mid = (low + high) / 2;
	if (elem[mid] == key)
		return mid;
	if (elem[mid] > key)
		return binSearch_rec(key, low, mid - 1);
	else
		return binSearch_rec(key, mid + 1, high);
}
#endif // !_VECTOR_SEARCH_H_
