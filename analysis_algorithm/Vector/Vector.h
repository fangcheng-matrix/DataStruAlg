#pragma once
#define OK 1//正确运行时的标识符
#define ERROR -1//运行异常时的标识符
#define DEFAULT_CAPACITY 100//顺序表的默认容量

template<typename T>
class Vector {
protected:
	int length;
	int capacity;
	T* elem;
	void expand() {
		if (length<capacity)
			return;//顺序表大小大于初始化大小，重新分配空间
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
	//定位给定位置元素，如果有则返回该元素
	T get_elem(int i) {
		if (!elem || i > length || i < 1)
			return{ };
		return elem[i - 1];
	}
	//定位指定元素，如果又则返回第一个匹配的元素位置
	int locate_elem(T e) {
		if (!elem)
			return ERROR;
		for (int i = 0; i < length; ++i) {
			if (e == elem[i])
				return i + 1;
		}
		return ERROR;
	}
	//删除指定位置的元素
	T remove(int i) {
		T e = elem[i];
		for (int j = i; j < length; ++j) {
			elem[j] = elem[j + 1];
		}
		--length;
		return e;
	}
	//顺序查找[low,high]区间，非递归实现
	int seqSearch(T key, int low, int high);
	//顺序查找非递归实现，默认全局查找
	int seqSearch(T key) {
		return seqSearch(key, 0, length - 1);
	}
	//顺序查找[low,high]区间，递归实现
	int seqSearch_rec(T key, int low, int higt);
	//顺序查找默认全局查找，递归实现
	int seqSearch_rec(T key) {
		return seqSearch_rec(key, 0, length - 1);
	}
	//非递归折半查找
	int binSearch(T key, int low, int high);
	int binSearch(T key) {
		return binSearch(key, 0, length - 1);
	}
	//递归折半查找
	int binSearch_rec(T key, int low, int high);
	int binSearch_rec(T key) {
		return binSearch_rec(key, 0, length - 1);
	}

public:
	//对[low,high]区间中的元素以dk间隔进行插入排序
	void insertSort(int low, int high, int dk = 1);
	//默认对全局元素进行插入排序
	void insertSort() {
		insertSort(0, length - 1);
	}
	//按增量序列对顺序表进行希尔排序
	void shellSort(Vector<int>& dlta);

private:
	//快速排序
	int partition(int low, int high);
public:
	void quickSort(int low, int high);
	void quickSort() {
		quickSort(0, length - 1);
	}

public:
	//直接选择排序
	void selectSort(int low, int high);
	void selectSort() {
		selectSort(0, length - 1);
	}

public:
	//堆排序
	void heapSort(int low, int high);
	void heapSort() {
		heapSort(0, length - 1);
	}

private:
	//归并排序
	void merge(int low, int mid, int high);
public:
	void mergeSort(int low, int high);
	void mergeSort() {
		mergeSort(0, length - 1);
	}
};