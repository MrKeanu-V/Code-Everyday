/*
200. Number of Islands [Medium - 4]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
并查集：
1. 并查集是一种树形的数据结构，用于处理一些不相交集合的合并及查询问题。
2. 并查集通常包含两个操作：1）find：确定元素属于哪个集合；2）union：将两个集合合并为一个集合。
3. 并查集通常用数组实现，数组中每个元素代表一个集合中的一个元素，每个元素都有一个指向父元素的指针，根元素的父元素指向自己。
*/

// 并查集模板
class UnionFind {
public:
	// 初始化并查集
	UnionFind(vector<vector<char>>& grid) {
		count = 0;
		int m = grid.size(), n = grid[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
					count++;
				}
				else {
					parent.push_back(-1);
				}
				rank.push_back(0);
			}
		}
	}

	int find(int x) {
		if (parent[x] != x) parent[x] = find(parent[x]);	// 路径压缩
		return parent[x];
	}

	void unite(int x, int y) {
		int rootx = find(x), rooty = find(y);
		if (rootx != rooty) {
			if(rank[rootx] < rank[rooty])
				swap(rootx, rooty);
			parent[rooty] = rootx;
			if (rank[rootx] == rank[rooty]) rank[rootx]++;
			count--;
		}	
	}

	int getCount() { return count; }
private:
	vector<int> parent; // 并查集数组，树形数组，保存父节点
	vector<int> rank;	// 树的高度
	int count; // 非连通分量个数
};

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int mr = grid.size(), mc = grid[0].size();
		if (!mr || !mc) return 0;

		UnionFind uf(grid);
		for (int r = 0; r < mr; r++) {
			for (int c = 0; c < mc; c++) {
				if (grid[r][c] == '1') {
					grid[r][c] = '0';	// visited
					if (r - 1 >= 0 && grid[r - 1][c] == '1') uf.unite(r * mc + c, (r - 1) * mc + c);	// 合并
					if (r + 1 < mr && grid[r + 1][c] == '1') uf.unite(r * mc + c, (r + 1) * mc + c);
					if (c - 1 >= 0 && grid[r][c - 1] == '1') uf.unite(r * mc + c, r * mc + c - 1);
					if (c + 1 < mc && grid[r][c + 1] == '1') uf.unite(r * mc + c, r * mc + c + 1);
				}
			}
		}
		return uf.getCount();
	}
};

int main() {
	Solution sln;
	vector<vector<char>> grid = { {'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'} };
	cout << sln.numIslands(grid) << endl;
	return 0;
}