#include "../List/List.h"
template<typename T>
class CList :public List<T> {
public:
	CList() {
		//cout << "派生类无参构造函数调用\n";
		this->header->next = this->header;
	}
	CList(T const& e) {
		//cout << "派生类有参构造函数调用\n";
		this->header->next = this->header;
	}
	//还原成单链表，程序会自动调用父类单链表的析构函数
	~CList() {
		get_node(this->_size)->next = NULL;
	}
	//重写删除循环链表结点
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
	//重写返回第i个结点函数
	LNode<T>* get_node(int i) {
		LNode<int>* p = this->header;
		for (int j = 0; j < i; j++) {
			p = p->next;
		}
		return p;
	}
	//通过循环查找指定结点的上一个结点
	LNode<T>* lastNode(LNode<T>* p) {
		LNode<T>* q = p->next;
		for (int i = 0; i < this->size() - 1; i++) {
			q = q->next;
		}
		return q;
	}
};