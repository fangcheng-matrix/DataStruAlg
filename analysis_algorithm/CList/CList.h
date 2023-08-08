#include "../List/List.h"
template<typename T>
class CList :public List<T> {
public:
	CList() {
		//cout << "�������޲ι��캯������\n";
		this->header->next = this->header;
	}
	CList(T const& e) {
		//cout << "�������вι��캯������\n";
		this->header->next = this->header;
	}
	//��ԭ�ɵ�����������Զ����ø��൥�������������
	~CList() {
		get_node(this->_size)->next = NULL;
	}
	//��дɾ��ѭ��������
	T remove(LNode<T>* p) {
		T e = p->data;
		LNode<T>* q = lastNode(p);
		q->next = p->next;
		this->_size--;
		if (p == this->header) {
			this->header = p->next;
		}
		delete p;
		return e;
	}
	//��д���ص�i����㺯��
	LNode<T>* get_node(int i) {
		LNode<int>* p = this->header;
		for (int j = 0; j < i; j++) {
			p = p->next;
		}
		return p;
	}
	//ͨ��ѭ������ָ��������һ�����
	LNode<T>* lastNode(LNode<T>* p) {
		LNode<T>* q = p->next;
		for (int i = 0; i < this->size() - 1; i++) {
			q = q->next;
		}
		return q;
	}
};