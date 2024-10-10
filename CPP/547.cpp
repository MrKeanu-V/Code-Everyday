/*
547. Number of Provinces [Medium - 4]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
private:
	// 关键在于：next和Base Case，即下一个遍历和边界条件
	void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i) {
		//if (visited[i]) return;
		//visited[i] = true;
		for (int j = 0; j < isConnected.size(); j++) {
			if (isConnected[i][j] && !visited[j]) {
				visited[i] = true;
				dfs(isConnected, visited, j);
			}
		}
	}
public:
	// 解法一 BFS
	int findCircleNum1(vector<vector<int>>& isConnected) {
		int n = isConnected.size(), cnt = 0;
		vector<bool> visited(n, false);
		queue<int> q;
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				visited[i] = 1;
				q.push(i);
				while (!q.empty()) {
					int j = q.front();
					q.pop();
					for (int k = 0; k < n; k++) {
						if (isConnected[j][k] && !visited[k]) {
							visited[k] = true;
							q.push(k);
						}
					}
				}
				cnt++;
			}
		}
		return cnt;
	}

	// 解法二 DFS
	int findCircleNum2(vector<vector<int>>& isConnected) {
		int n = isConnected.size(), cnt = 0;
		vector<bool> visited(n, false);
		
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				dfs(isConnected, visited, i);
				cnt++;
			}
		}

		return cnt;
	}
	/*
	并查集：
	1. 并查集是一种树形的数据结构，用于处理一些不相交集合的合并及查询问题。
	2. 并查集通常包含两个操作：1）find：确定元素属于哪个集合；2）union：将两个集合合并为一个集合。
	3. 并查集通常用数组实现，数组中每个元素代表一个集合中的一个元素，每个元素都有一个指向父元素的指针，根元素的父元素指向自己。
	*/
	int find(vector<int>& parent, int x) {	// 一般在find时，会进行路径压缩
		if (parent[x] != x) parent[x] = find(parent, parent[x]);	// 递归路径压缩
		return parent[x];
	}
	void unite(vector<int>& parent, int x, int y) {
		parent[find(parent, x)] = find(parent, y);
	}
	// 解法三 并查集
	int findCircleNum(vector<vector<int>>& isConnected) {
		int n = isConnected.size(), cnt = 0;
		// 初始化并查集
		vector<int> parent(n);
		for(int i=0;i<n;i++) parent[i] = i;

		for(int i=0;i<n;i++)
			for (int j = 0; j < n; j++)
				if (isConnected[i][j]) unite(parent, i, j);
		// 统计集合个数
		for (int i = 0; i < n; i++)
			if (parent[i] == i) cnt++;
		return cnt;
	}
};

int main() {
	Solution sln;
    vector<vector<int>> isConnected = { {1,1,0},{1,1,0},{0,0,1} };
	cout << sln.findCircleNum(isConnected) << endl;
	return 0;
}