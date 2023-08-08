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
	//使用头节点存储某些信息，不随链表插入改变位置
	List(T info) {
		init();
		header->data = info;
	}
	//析构函数
	~List() {
		LNode<T>* p = header;
		while (header) {
			p = p->next;
			delete header;
			header = p;
		}
	}
	//返回头节点指针
	LNode<T>* head() const {
		return header->next;
	}
	//返回链表信息
	T& info() {
		return header->data;
	}
	//默认用头插法插入，开辟新空间
	void insert(T const& e) {
		_size++;
		LNode<T>* p = new LNode<T>(e, header->next);
		header->next = p;
	}
	//在指定节点后插入
	void insert(LNode<T>* p, T const& e) {
		if (!p)
			return;
		_size++;
		//新建节点s并插入
		LNode<T>* s = new LNode<T>(e, p->next);
		p->next = s;
	}
	//返回第i个节点
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
	//返回第一个匹配元素的位置
	int locate_elem(T e) {
		LNode<T>* p = header->next;
		for (int i = 1; p; p = p->next, i++) {
			if (p->data == e)
				return i;
		}
		return 0;
	}
	//删除单链表中的有效节点，单链表逻辑关系不变
	T remove(LNode<T>* p) {
		T e = p->data;//备份删除节点数据
		int location = locate_elem(e) - 1;//找到前一个节点位置
		LNode<T>* q = get_node(location);
		q->next = p->next;
		_size--;
		delete p;//删除并释放节点
		return e;
	}
	//按数据大小合并链表
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