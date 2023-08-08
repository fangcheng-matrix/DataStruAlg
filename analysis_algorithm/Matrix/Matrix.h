#pragma once
#include <iostream>
using namespace std;
template<typename T>
struct Triple {
	int i, j;//非零元素的行下标和列下标
	T elem;
};

template<typename T>
struct Matrix {
	int row, col;
	int num;
	Triple<T>* data;
	Matrix(int r, int c, int n) :row(r), col(c), num(n) {
		data = new Triple<T>[num + 1];//非零三元组表，data[0]未使用
	}
	~Matrix() {
		delete[] data;
		cout << "析构" << endl;
	}
};