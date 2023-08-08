#ifndef NULL
#define NULL 0
#endif

template<typename T>
struct LNode
{
	T data;
	LNode<T>* next;
	LNode() { }
	LNode(T e, LNode<T>* n = NULL)
		:data(e), next(n) { }
};

#define ERROR 0
template<typename T>
class List {
protected:
	int _size;
	LNode<T>* header;

	void init() {
		header = new LNode<T>;
		header->next = NULL;
		_size = 0;
	}
public:
	int size() const {
		return _size;
	}
	bool empty() const {
		return !_size;
	}
	List() {
		init();
	}
	//ʹ��ͷ�ڵ�洢ĳЩ��Ϣ�������������ı�λ��
	List(T info) {
		init();
		header->data = info;
	}
	//��������
	~List() {
		LNode<T>* p = header;
		while (header) {
			p = p->next;
			delete header;
			header = p;
		}
	}
	//����ͷ�ڵ�ָ��
	LNode<T>* head() const {
		return header->next;
	}
	//����������Ϣ
	T& info() {
		return header->data;
	}
	//Ĭ����ͷ�巨���룬�����¿ռ�
	void insert(T const& e) {
		_size++;
		LNode<T>* p = new LNode<T>(e, header->next);
		header->next = p;
	}
	//��ָ���ڵ�����
	void insert(LNode<T>* p, T const& e) {
		if (!p)
			return;
		_size++;
		//�½��ڵ�s������
		LNode<T>* s = new LNode<T>(e, p->next);
		p->next = s;
	}
	//���ص�i���ڵ�
	LNode<T>* get_node(int i) {
		int j = 0;
		LNode<T>* p = header;
		while (p && j < i) {
			p = p->next;
			++j;
		}
		if (!p || j != i)
			return NULL;
		else
			return p;
	}
	//���ص�һ��ƥ��Ԫ�ص�λ��
	int locate_elem(T e) {
		LNode<T>* p = header->next;
		for (int i = 1; p; p = p->next, i++) {
			if (p->data == e)
				return i;
		}
		return 0;
	}
	//ɾ���������е���Ч�ڵ㣬�������߼���ϵ����
	T remove(LNode<T>* p) {
		T e = p->data;//����ɾ���ڵ�����
		int location = locate_elem(e) - 1;//�ҵ�ǰһ���ڵ�λ��
		LNode<T>* q = get_node(location);
		q->next = p->next;
		_size--;
		delete p;//ɾ�����ͷŽڵ�
		return e;
	}
	//�����ݴ�С�ϲ�����
	void merge(List<T>& L) {
		LNode<T>* pa = this->head(), * pb = L.head();
		LNode<T>* pc = header;
		while (pa && pb) {
			if (pa->data <= pb->data) {
				pc->next = pa;
				pc = pa;
				pa = pa->next;
			}
			else {
				pc->next = pb;
				pc = pb;
				pb = pb->next;
			}
		}
		pc->next = pa ? pa : pb;
		_size += L.size();
		L.header->next = NULL;
		L._size = 0;
	}
};