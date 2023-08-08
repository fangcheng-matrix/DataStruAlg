#pragma once
#include <iostream>
#include "Matrix.h"
using namespace std;

void create_Matrix(Matrix<int>& M) {
	cout << "�밴��������˳������ϡ�����\n";
	cout << M.num << "������Ԫ����Ϣ��\n";
	for (int k = 1; k <= M.num; k++) {
		cout << "��" << k << "��Ԫ�ص��бꡢ�б��Լ�Ԫ��ֵΪ��";
		cin >> M.data[k].i >> M.data[k].j >> M.data[k].elem;
	}
	cout << endl;
}
//������Ԫ���洢��ʾ����ϡ�����M��ת�þ���T
Matrix<int> FastTranspose_Matrix(Matrix<int>& M) {
	Matrix<int> T(M.col, M.row, M.num);
	if (M.num == 0)
		return T;
	int* num = new int[M.col + 1]();
	int* cpot = new int[M.col + 1]();
	//����num[col]��ֵ
	for (int t = 1; t <= M.num; t++) {
		num[M.data[t].j]++;
	}
	//����cpot[col]��ֵ
	cpot[1] = 1;
	for (int col = 2; col <= M.col; col++) {
		cpot[col] = cpot[col - 1] + num[col - 1];
	}
	//ɨ�����M����Ԫ���a.data������ת�þ���T����Ԫ���b.data
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
	cout << "����" << M.num << "������Ԫ�أ�\n";
	int t = 1;
	cout << "ϡ�����Ϊ��\n";
	for (int p = 1; p <= M.row; p++) {
		for (int q = 1; q <= M.col; q++) {
			//��ӡ����Ԫ��
			if (M.data[t].i == p && M.data[t].j == q)
				printf("%5d", M.data[t++].elem);
			//��ӡ��Ԫ��
			else
				printf("%5d", 0);
		}
		cout << endl;
	}
	system("pause");
	cout << "\nϡ�������Ԫ��˳���Ϊ��\n";
	printf("%5c%5c%5c\n", 'i', 'j', 'v');
	for (int k = 1; k <= M.num; k++) {
		printf("%5d%5d%5d\n", M.data[k].i, M.data[k].j, M.data[k].elem);
	}
	system("pause");
}

int main() {
	int r, c, n;
	cout << "����ϡ�����������������";
	cin >> r >> c;
	cout << "����ϡ��������Ԫ�ظ�����";
	cin >> n;
	Matrix<int> M(r, c, n);
	create_Matrix(M);
	print_Matrix(M);
	Matrix<int> T = FastTranspose_Matrix(M);
	cout << "\nת�ú��ϡ�����Ϊ��\n";
	print_Matrix(T);
	
	return 0;
}