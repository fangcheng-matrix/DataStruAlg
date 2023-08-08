#pragma once
#include "../Vector/Vector.h"

//以顺序表为基类，派生出栈模板类
template <typename T>
class Stack :public Vector<T> {
	//将顺序表的末端作为栈顶
public:
	//查看栈顶元素
	T top() {
		return this->get_elem(this->size());
	}
	//入栈即将新元素插入顺序表末端
	void push(T const& e) {
		this->insert(e);
	}
	//出栈即删除末端元素并返回其值
	T pop() {
		return this->remove(this->size()-1);
	}
};