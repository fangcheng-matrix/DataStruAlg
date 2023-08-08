#pragma once
#include "../Vector/Vector.h"
#include <iostream>

class String :public Vector<char> {
public:
	//构造函数，先插入'\0'作为终止符
	String() {
		Vector<char>::insert('\0');
	}
	//重载构造函数，根据字符数组初始化，同时调用参数为空的构造函数
	String(const char* str) :String() {
		for (int i = 0; str[i] != '\0'; i++)
			insert(str[i]);
	}
	//重写，由于最后一位为'\0'，故将规模-1
	int size() const {
		return length - 1;
	}
	//重写，length最小为1
	bool empty() const {
		return length <= 1;
	}
	//插入时调用基类方法插入，在'\0'前插入
	void insert(char const& e) {
		Vector<char>::insert(length - 1, e);
	}
	String* substr(int pos, int len) {
		//位置或长度出错返回空串
		String* sub = new String();
		if (pos > 0 && len > 0 && pos - 1 + len < length) {
			for (int i = 0; i < len; ++i) {
				sub->insert(elem[pos - 1 + i]);
			}
		}
		return sub;
	}
	//将串S连入当前串
	void contact(String& S) {
		for (int i = 0; i != S.size(); ++i) {
			insert(S[i]);
		}
	}

friend std::ostream& operator<<(std::ostream& out, const String& S) {
		out << S.elem;
		return out;
	}
};