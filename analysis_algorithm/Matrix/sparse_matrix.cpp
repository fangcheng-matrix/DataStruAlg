#pragma once
#include <iostream>
#include "Matrix.h"
using namespace std;

void create_Matrix(Matrix<int>& M) {
	cout << "请按照行优先顺序输入稀疏矩阵\n";
	cout << M.num << "个非零元素信息：\n";
	for (int k = 1; k <= M.num; k++) {
		cout << "第" << k << "个元素的行标、列标以及元素值为：";
		cin >> M.data[k].i >> M.data[k].j >> M.data[k].elem;
	}
	cout << endl;
}
//采用三元组表存储表示，求稀疏矩阵M的转置矩阵T
Matrix<int> FastTranspose_Matrix(Matrix<int>& M) {
	Matrix<int> T(M.col, M.row, M.num);
	if (M.num == 0)
		return T;
	int* num = new int[M.col + 1]();
	int* cpot = new int[M.col + 1]();
	//计算num[col]的值
	for (int t = 1; t <= M.num; t++) {
		num[M.data[t].j]++;
	}
	//计算cpot[col]的值
	cpot[1] = 1;
	for (int col = 2; col <= M.col; col++) {
		cpot[col] = cpot[col - 1] + num[col - 1];
	}
	//扫描矩阵M的三元组表a.data，生成转置矩阵T的三元组表b.data
	for (int p = 1; p <= M.num; p++) {
		int q = cpot[M.data[p].j];
		T.data[q].i = M.data[p].j;
		T.data[q].j = M.data[p].i;
		T.data[q].elem = M.data[p].elem;
		cpot[q]++;
	}
	delete[] num;
	delete[] cpot;
	return T;
}
void print_Matrix(Matrix<int>& M) {
	cout << "共有" << M.num << "个非零元素：\n";
	int t = 1;
	cout << "稀疏矩阵为：\n";
	for (int p = 1; p <= M.row; p++) {
		for (int q = 1; q <= M.col; q++) {
			//打印非零元素
			if (M.data[t].i == p && M.data[t].j == q)
				printf("%5d", M.data[t++].elem);
			//打印零元素
			else
				printf("%5d", 0);
		}
		cout << endl;
	}
	system("pause");
	cout << "\n稀疏矩阵三元组顺序表为：\n";
	printf("%5c%5c%5c\n", 'i', 'j', 'v');
	for (int k = 1; k <= M.num; k++) {
		printf("%5d%5d%5d\n", M.data[k].i, M.data[k].j, M.data[k].elem);
	}
	system("pause");
}

int main() {
	int r, c, n;
	cout << "输入稀疏矩阵行数与列数：";
	cin >> r >> c;
	cout << "输入稀疏矩阵非零元素个数：";
	cin >> n;
	Matrix<int> M(r, c, n);
	create_Matrix(M);
	print_Matrix(M);
	Matrix<int> T = FastTranspose_Matrix(M);
	cout << "\n转置后的稀疏矩阵为：\n";
	print_Matrix(T);
	
	return 0;
}