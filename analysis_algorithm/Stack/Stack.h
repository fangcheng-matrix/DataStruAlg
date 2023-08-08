#pragma once
#include "../Vector/Vector.h"

//��˳���Ϊ���࣬������ջģ����
template <typename T>
class Stack :public Vector<T> {
	//��˳����ĩ����Ϊջ��
public:
	//�鿴ջ��Ԫ��
	T top() {
		return this->get_elem(this->size());
	}
	//��ջ������Ԫ�ز���˳���ĩ��
	void push(T const& e) {
		this->insert(e);
	}
	//��ջ��ɾ��ĩ��Ԫ�ز�������ֵ
	T pop() {
		return this->remove(this->size()-1);
	}
};