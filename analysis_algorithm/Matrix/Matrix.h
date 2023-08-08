#pragma once
#include <iostream>
using namespace std;
template<typename T>
struct Triple {
	int i, j;//����Ԫ�ص����±�����±�
	T elem;
};

template<typename T>
struct Matrix {
	int row, col;
	int num;
	Triple<T>* data;
	Matrix(int r, int c, int n) :row(r), col(c), num(n) {
		data = new Triple<T>[num + 1];//������Ԫ���data[0]δʹ��
	}
	~Matrix() {
		delete[] data;
		cout << "����" << endl;
	}
};