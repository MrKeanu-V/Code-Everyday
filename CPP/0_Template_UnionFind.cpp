/*
	���鼯��
	1. ���鼯��һ�����ε����ݽṹ�����ڴ���һЩ���ཻ���ϵĺϲ�����ѯ���⡣
	2. ���鼯ͨ����������������1��find��ȷ��Ԫ�������ĸ����ϣ�2��union�����������Ϻϲ�Ϊһ�����ϡ�
	3. ���鼯ͨ��������ʵ�֣�������ÿ��Ԫ�ش���һ�������е�һ��Ԫ�أ�ÿ��Ԫ�ض���һ��ָ��Ԫ�ص�ָ�룬��Ԫ�صĸ�Ԫ��ָ���Լ���
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