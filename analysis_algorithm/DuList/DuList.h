#ifndef NULL
#define NULL 0
#endif // !NULL

template<typename T>
struct DuLNode {
	T data;
	DuLNode<T>* prior, * next;
	DuLNode() { };
	DuLNode(T e, DuLNode<T>* p = NULL, DuLNode<T>* n = NULL)
		:data(e), prior(p), next(n) { };
};

template<typename T>
class DuList {
private:
	int _size;
	DuLNode<T>* head, * tail;
protected:
	void init() {
		head = new DuLNode<T>;
		tail = new DuLNode<T>;
		head->next = tail;
		head->prior = NULL;
		tail->prior = head;
		tail->next = NULL;
		_size = 0;
	}
public:
	int size() const {
		return _size;
	}
	bool empty() const {
		return !_size;
	}
	DuLNode<T>* first() const {
		return head->next;
	}
	DuLNode<T>* last() const {
		return tail->prior;
	}
	DuList() {
		init();
	}
	~DuList() {
		DuLNode<T>* p = head;
		while (head) {
			p = p->next;
			delete head;
			head = p;
		}
	}
	//��ָ���������
	void insert_after(DuLNode<T>* p, T const& e) {
		_size++;
		DuLNode<T>* s = new DuLNode<T>(e, p, p->next);
		p->next->prior = s;
		p->next = s;
	}
	//��ָ�����ǰ����
	void insert_before(DuLNode<T>* p, T const& e) {
		_size++;
		DuLNode<T>* q = new DuLNode<T>(e, p->prior, p);
		p->prior->next = q;
		p->prior = q;
	}
	//��Ϊ��һ��������
	void insert_first(T const& e) {
		insert_after(head, e);
	}
	//��Ϊ���һ��������
	void insert_last(T const& e) {
		insert_before(tail, e);
	}
	//���ص�i�����
	DuLNode<T>* get_node(int i){
		int j = 0;
		DuLNode<T>* p = head;
		while (p != tail && j < i) {
			p = p->next;
			++j;
		}
		if (!p || j > i) return NULL;
		else return p;
	}
	//���ص�һ��ƥ��Ԫ�ص�λ��
	int locate_elem(T e) {
		DuLNode<T>* p = head->next;
		for (int i = 0; p != tail; p = p->next, i++) {
			if (p->data == e) {
				return i;
			}
		}
		return 0;
	}

	T remove(DuLNode<T>* p) {
		T e = p->data;
		p->prior->next = p->next;
		p->next->prior = p->prior;
		_size--;
		delete p;
		return e;
	}
};