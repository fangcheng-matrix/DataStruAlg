#pragma once
#include "../Vector/Vector.h"
#include <iostream>

class String :public Vector<char> {
public:
	//���캯�����Ȳ���'\0'��Ϊ��ֹ��
	String() {
		Vector<char>::insert('\0');
	}
	//���ع��캯���������ַ������ʼ����ͬʱ���ò���Ϊ�յĹ��캯��
	String(const char* str) :String() {
		for (int i = 0; str[i] != '\0'; i++)
			insert(str[i]);
	}
	//��д���������һλΪ'\0'���ʽ���ģ-1
	int size() const {
		return length - 1;
	}
	//��д��length��СΪ1
	bool empty() const {
		return length <= 1;
	}
	//����ʱ���û��෽�����룬��'\0'ǰ����
	void insert(char const& e) {
		Vector<char>::insert(length - 1, e);
	}
	String* substr(int pos, int len) {
		//λ�û򳤶ȳ����ؿմ�
		String* sub = new String();
		if (pos > 0 && len > 0 && pos - 1 + len < length) {
			for (int i = 0; i < len; ++i) {
				sub->insert(elem[pos - 1 + i]);
			}
		}
		return sub;
	}
	//����S���뵱ǰ��
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