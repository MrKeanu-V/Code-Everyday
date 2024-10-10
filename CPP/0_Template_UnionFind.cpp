/*
	并查集：
	1. 并查集是一种树形的数据结构，用于处理一些不相交集合的合并及查询问题。
	2. 并查集通常包含两个操作：1）find：确定元素属于哪个集合；2）union：将两个集合合并为一个集合。
	3. 并查集通常用数组实现，数组中每个元素代表一个集合中的一个元素，每个元素都有一个指向父元素的指针，根元素的父元素指向自己。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind {
public:
	UnionFind(int n) {
		parent.resize(n);
		for (int i = 0; i < n; i++) parent[i] = i;
	}
	int find(int x) {
		if (parent[x] != x) parent[x] = find(parent[x]);
		return parent[x];
	}
	void unite(int x, int y) {
		parent[find(x)] = find(y);
	}
	int count() {
		int cnt = 0;
		for (int i = 0; i < parent.size(); i++)
			if (parent[i] == i) cnt++;
		return cnt;
	}
private:
	vector<int> parent;
};