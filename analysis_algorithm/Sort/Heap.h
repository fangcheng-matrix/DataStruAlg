#pragma once
#ifndef _HEAP_H_
#define _HEAP_H_

#include "../Vector/Vector.h"

//堆的数据结构的抽象类
template<typename T>
class Heap :public Vector<T> {
protected:
	//指定比较函数，用于用于大顶堆和小顶堆的继承重载
	//逻辑为父结点与子结点的比较要求
	virtual bool compare(T x, T y) = 0;
	//返回第i个元素的父结点序号
	int parent(int i) {
		return (i - 1) >> 1;
	}
	//返回第i个元素的左孩子结点序号
	int lchild(int i) {
		return (i << 1) + 1;
	}
	//返回第i个元素的右孩子结点序号
	int rchild(int i) {
		return (i + 1) << 1;
	}
	//对顺序表中的第i个元素进行上浮操作
	void shiftUp(int i) {
		T tmp = this->elem[i];
		//上浮到根节点结束
		while (i) {
			//若当前结点与父结点比较失败，上浮结束
			if (!compare(tmp, this->elem[parent(i)]))
				break;
			//否则进行交换
			this->elem[i] = this->elem[parent(i)];
			i = parent(i);
		}
		this->elem[i] = tmp;
	}
	//对顺序表中第i个元素进行下沉操作
	void shiftDown(int i) {
		T tmp = this->elem[i];
		//下沉到最后的结点
		while (lchild(i) <= this->length) {
			int child = lchild(i);
			//child指向结果成功的孩子结点
			if (rchild(i) < this->length && compare(this->elem[rchild(i)], this->elem[lchild(i)]))
				child++;
			if (compare(tmp, this->elem[child]))
				break;
			this->elem[i] = this->elem[child];
			i = child;
		}
		this->elem[i] = tmp;
	}
	//根据数组array建立长度为n的堆
	void heapify(T* array, int n) {
		//插入所有元素
		for (int i = 0; i < n; i++) {
			this->insert(array[i]);
		}
		//只用对所有孩子结点不为空的父结点进行下沉
		for (int i = parent(this->length); i >= 0; i--) {
			shiftDown(i);
		}
	}
public:
	Heap() {

	}
	//返回堆顶元素
	T top() {
		return this->elem[0];
	}
	//将元素e插入堆中
	void push(T e) {
		this->insert(e);
		shiftUp(this->length - 1);
	}
	//删除堆顶元素并返回其值
	T pop() {
		T max = this->elem[0];
		//将堆顶元素与最后元素交换
		this->elem[0] = this->elem[--this->length];
		//将新的堆顶元素下沉
		shiftDown(0);
		return max;
	}
};
//大顶堆实现
template<typename T>
class MaxHeap :public Heap<T> {
protected:
	////指定比较函数，父结点比子结点大
	bool compare(T x, T y) {
		return x > y;
	}
public:
	MaxHeap() :Heap<T>() {

	}
	MaxHeap(T* array, int n) {
		this->heapify(array, n);
	}
};
//小顶堆实现
template<typename T>
class MinHeap :public Heap<T> {
protected:
	//指定比较函数，父结点比子结点小
	bool compare(T x, T y) {
		return x < y;
	}
public:
	MinHeap() :Heap<T>() {

	}
	MinHeap(T* array, int n) {
		this->heapify(array, n);
	}
};
#endif // !_HEAP_H_
