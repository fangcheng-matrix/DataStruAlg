#pragma once
#define DEFAULT_CAPACITY 10
//以顺序表的方式实现队列
template<typename T>
class Queue {
protected:
	int head, tail;
	int capacity;
	T* elem;
public:
	Queue(int c = DEFAULT_CAPACITY) :capacity(c) {
		elem = new T[capacity];
		head = tail = -1;
	}
	~Queue() {
		delete[] elem;
	}
	//入队，即未满时在尾部插入
	void enqueue(T const& e) {
		elem[++tail] = e;
	}
	T dequeue() {
		return elem[++head];
	}
	int size() const {
		return tail - head;
	}
	bool empty() const {
		return !size();
	}
	bool full() const {
		return tail >= capacity - 1;
	}
	T front() {
		return elem[head + 1];
	}
	T rear() {
		return elem[tail];
	}
};