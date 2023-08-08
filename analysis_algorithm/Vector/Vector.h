#pragma once
#define OK 1//��ȷ����ʱ�ı�ʶ��
#define ERROR -1//�����쳣ʱ�ı�ʶ��
#define DEFAULT_CAPACITY 100//˳����Ĭ������

template<typename T>
class Vector {
protected:
	int length;
	int capacity;
	T* elem;
	void expand() {
		if (length<capacity)
			return;//˳����С���ڳ�ʼ����С�����·���ռ�
		if (capacity < DEFAULT_CAPACITY)
			capacity = DEFAULT_CAPACITY;
		T* oldElem = elem;
		elem = new T[capacity <<= 1];
		for (int i = 0; i < length; i++) {
			elem[i] = oldElem[i];
		}
		delete[] oldElem;
	}
public:
	Vector(int c = DEFAULT_CAPACITY) :capacity(c) {
		elem = new T[capacity];
		length = 0;
	}
	~Vector() {
		delete[] elem;
	}
	int size() const {
		return length;
	}
	bool empty() const {
		return !length;
	}
	T& operator[](int r) const {
		return elem[r];
	}
	void insert(int r, T const& e) {
		expand();
		for (int i = length; i > r; i--) {
			elem[i] = elem[i - 1];
		}
		elem[r] = e;
		length++;
	}
	void insert(T const& e) {
		insert(length, e);
	}
	//��λ����λ��Ԫ�أ�������򷵻ظ�Ԫ��
	T get_elem(int i) {
		if (!elem || i > length || i < 1)
			return{ };
		return elem[i - 1];
	}
	//��λָ��Ԫ�أ�������򷵻ص�һ��ƥ���Ԫ��λ��
	int locate_elem(T e) {
		if (!elem)
			return ERROR;
		for (int i = 0; i < length; ++i) {
			if (e == elem[i])
				return i + 1;
		}
		return ERROR;
	}
	//ɾ��ָ��λ�õ�Ԫ��
	T remove(int i) {
		T e = elem[i];
		for (int j = i; j < length; ++j) {
			elem[j] = elem[j + 1];
		}
		--length;
		return e;
	}
	//˳�����[low,high]���䣬�ǵݹ�ʵ��
	int seqSearch(T key, int low, int high);
	//˳����ҷǵݹ�ʵ�֣�Ĭ��ȫ�ֲ���
	int seqSearch(T key) {
		return seqSearch(key, 0, length - 1);
	}
	//˳�����[low,high]���䣬�ݹ�ʵ��
	int seqSearch_rec(T key, int low, int higt);
	//˳�����Ĭ��ȫ�ֲ��ң��ݹ�ʵ��
	int seqSearch_rec(T key) {
		return seqSearch_rec(key, 0, length - 1);
	}
	//�ǵݹ��۰����
	int binSearch(T key, int low, int high);
	int binSearch(T key) {
		return binSearch(key, 0, length - 1);
	}
	//�ݹ��۰����
	int binSearch_rec(T key, int low, int high);
	int binSearch_rec(T key) {
		return binSearch_rec(key, 0, length - 1);
	}

public:
	//��[low,high]�����е�Ԫ����dk������в�������
	void insertSort(int low, int high, int dk = 1);
	//Ĭ�϶�ȫ��Ԫ�ؽ��в�������
	void insertSort() {
		insertSort(0, length - 1);
	}
	//���������ж�˳������ϣ������
	void shellSort(Vector<int>& dlta);

private:
	//��������
	int partition(int low, int high);
public:
	void quickSort(int low, int high);
	void quickSort() {
		quickSort(0, length - 1);
	}

public:
	//ֱ��ѡ������
	void selectSort(int low, int high);
	void selectSort() {
		selectSort(0, length - 1);
	}

public:
	//������
	void heapSort(int low, int high);
	void heapSort() {
		heapSort(0, length - 1);
	}

private:
	//�鲢����
	void merge(int low, int mid, int high);
public:
	void mergeSort(int low, int high);
	void mergeSort() {
		mergeSort(0, length - 1);
	}
};