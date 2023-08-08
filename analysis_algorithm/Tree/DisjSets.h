#pragma once
#ifndef _DISJESTS_H_
#define _DISJESTS_H_

class DisjSets {
private:
	int* parent;
public:
	DisjSets(int num) {
		//并查集初始化，每个结点都是根节点
		parent = new int[num];
		for (int i = 0; i < num; i++) {
			parent[i] = -1;
		}
	}
	~DisjSets() {
		delete[] parent;
	}
	//递归进行并查集查询并进行路径压缩
	int find(int x) {
		//父节点大于0表示x不为根节点
		return parent[x] < 0 ? x : parent[x] = find(parent[x]);
	}
	//根据根节点数量（负数的绝对值）合并两个根节点
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
	//判断x和y结点是否在一个集合内
	bool inSame(int x, int y) {
		return find(x) == find(y);
	}
};
#endif // !_DISJESTS_H_
