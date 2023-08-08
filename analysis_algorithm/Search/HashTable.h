#pragma once
#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include "../List/List.h"
#include <iostream>
#define HASH_MAX 11

template<typename T>
class HashTable {
protected:
	int capacity;
	List<T>* chainHash;
public:
	HashTable(int c = HASH_MAX)
		:capacity(c) {
		chainHash = new List<T>[capacity];
	}
	~HashTable() {
		delete[] chainHash;
	}
	int size() const {
		int count = 0;
		for (int i = 0; i < capacity; i++)
			count += chainHash[i].size();
		return count;
	}
	bool empty() const {
		return !size();
	}
	//¹þÏ£º¯Êý£¬³ýÁôÓàÊý·¨
	int hashCode(T key) const {
		return key % capacity;
	}
	void insert(T key) {
		int index = hashCode(key);
		chainHash[index].insert(key);
	}
	LNode<T>* search(T key) {
		int index = hashCode(key);
		for (LNode<T>* p = chainHash[index].head(); p; p = p->next)
			if (p->data == key)
				return p;
		return NULL;
	}
	void remove(T key) {
		LNode<T>* p = search(key);
		if (!p)
			return;
		else
			chainHash[hashCode(key)].remove(p);
	}
	void print() {
		for (int i = 0; i < capacity; i++) {
			for (LNode<T>* p = chainHash[i].head(); p; p = p->next)
				std::cout << p->data << ' ';
			std::cout << endl;
		}
	}
};
#endif // !_HASHTABLE_H_
