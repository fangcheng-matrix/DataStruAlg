#pragma once
#ifndef _HEAP_H_
#define _HEAP_H_

#include "../Vector/Vector.h"

//�ѵ����ݽṹ�ĳ�����
template<typename T>
class Heap :public Vector<T> {
protected:
	//ָ���ȽϺ������������ڴ󶥶Ѻ�С���ѵļ̳�����
	//�߼�Ϊ��������ӽ��ıȽ�Ҫ��
	virtual bool compare(T x, T y) = 0;
	//���ص�i��Ԫ�صĸ�������
	int parent(int i) {
		return (i - 1) >> 1;
	}
	//���ص�i��Ԫ�ص����ӽ�����
	int lchild(int i) {
		return (i << 1) + 1;
	}
	//���ص�i��Ԫ�ص��Һ��ӽ�����
	int rchild(int i) {
		return (i + 1) << 1;
	}
	//��˳����еĵ�i��Ԫ�ؽ����ϸ�����
	void shiftUp(int i) {
		T tmp = this->elem[i];
		//�ϸ������ڵ����
		while (i) {
			//����ǰ����븸���Ƚ�ʧ�ܣ��ϸ�����
			if (!compare(tmp, this->elem[parent(i)]))
				break;
			//������н���
			this->elem[i] = this->elem[parent(i)];
			i = parent(i);
		}
		this->elem[i] = tmp;
	}
	//��˳����е�i��Ԫ�ؽ����³�����
	void shiftDown(int i) {
		T tmp = this->elem[i];
		//�³������Ľ��
		while (lchild(i) <= this->length) {
			int child = lchild(i);
			//childָ�����ɹ��ĺ��ӽ��
			if (rchild(i) < this->length && compare(this->elem[rchild(i)], this->elem[lchild(i)]))
				child++;
			if (compare(tmp, this->elem[child]))
				break;
			this->elem[i] = this->elem[child];
			i = child;
		}
		this->elem[i] = tmp;
	}
	//��������array��������Ϊn�Ķ�
	void heapify(T* array, int n) {
		//��������Ԫ��
		for (int i = 0; i < n; i++) {
			this->insert(array[i]);
		}
		//ֻ�ö����к��ӽ�㲻Ϊ�յĸ��������³�
		for (int i = parent(this->length); i >= 0; i--) {
			shiftDown(i);
		}
	}
public:
	Heap() {

	}
	//���ضѶ�Ԫ��
	T top() {
		return this->elem[0];
	}
	//��Ԫ��e�������
	void push(T e) {
		this->insert(e);
		shiftUp(this->length - 1);
	}
	//ɾ���Ѷ�Ԫ�ز�������ֵ
	T pop() {
		T max = this->elem[0];
		//���Ѷ�Ԫ�������Ԫ�ؽ���
		this->elem[0] = this->elem[--this->length];
		//���µĶѶ�Ԫ���³�
		shiftDown(0);
		return max;
	}
};
//�󶥶�ʵ��
template<typename T>
class MaxHeap :public Heap<T> {
protected:
	////ָ���ȽϺ������������ӽ���
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
//С����ʵ��
template<typename T>
class MinHeap :public Heap<T> {
protected:
	//ָ���ȽϺ������������ӽ��С
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
