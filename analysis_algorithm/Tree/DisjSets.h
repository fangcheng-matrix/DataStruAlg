#pragma once
#ifndef _DISJESTS_H_
#define _DISJESTS_H_

class DisjSets {
private:
	int* parent;
public:
	DisjSets(int num) {
		//���鼯��ʼ����ÿ����㶼�Ǹ��ڵ�
		parent = new int[num];
		for (int i = 0; i < num; i++) {
			parent[i] = -1;
		}
	}
	~DisjSets() {
		delete[] parent;
	}
	//�ݹ���в��鼯��ѯ������·��ѹ��
	int find(int x) {
		//���ڵ����0��ʾx��Ϊ���ڵ�
		return parent[x] < 0 ? x : parent[x] = find(parent[x]);
	}
	//���ݸ��ڵ������������ľ���ֵ���ϲ��������ڵ�
	void unionSets(int x, int y) {
		if (inSame(x, y)) {
			return;
		}
		int root1 = find(x), root2 = find(y);
		if (parent[root2] < parent[root1]) {
			parent[root2] += parent[root1];
			parent[root1] = root2;
		}
		else {
			parent[root1] += parent[root2];
			parent[root2] = root1;
		}
	}
	//�ж�x��y����Ƿ���һ��������
	bool inSame(int x, int y) {
		return find(x) == find(y);
	}
};
#endif // !_DISJESTS_H_
