/*
200. Number of Islands [Medium - 4]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
网格图是介于链表、树和图之间的数据结构，网格图的大部分问题还是DFS或者BFS的应用。
只是在其DFS、BFS过程是基于树的变种，网格图本质上是图因此需要考虑重复遍历的问题。
以DFS为例，所有的搜索本质上都只有两个要点：1、搜索方向（next）；2、搜索结束条件（Base Case）。
*/
class Solution {
private:
	int m, n;
	bool isInRange(int r, int c) {
		if (r < 0 || r >= m || c < 0 || c >= n) return false;
		return true;
	}
	void dfs(vector<vector<char>>& grid, int r, int c) {
		if (!isInRange(r, c) || grid[r][c] == '0') return;
		grid[r][c] = '0';
		dfs(grid, r - 1, c);
		dfs(grid, r + 1, c);
		dfs(grid, r, c - 1);
		dfs(grid, r, c + 1);
	}

public:
	int numIslands(vector<vector<char>>& grid) {
		m = grid.size(), n = grid[0].size();
		int res = 0;
		for (int r = 0; r < m; r++)
			for (int c = 0; c < n; c++)
				if (grid[r][c] == '1') {
					res++;
					dfs(grid, r, c);
				}

		return res;
	}
};

int main() {
	Solution sln;
    vector<vector<char>> grid = { {'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'} };
	cout << sln.numIslands(grid) << endl;
	return 0;
}