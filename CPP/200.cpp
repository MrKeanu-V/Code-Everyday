/*
200. Number of Islands [Medium - 4]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
����ͼ�ǽ�����������ͼ֮������ݽṹ������ͼ�Ĵ󲿷����⻹��DFS����BFS��Ӧ�á�
ֻ������DFS��BFS�����ǻ������ı��֣�����ͼ��������ͼ�����Ҫ�����ظ����������⡣
��DFSΪ�������е����������϶�ֻ������Ҫ�㣺1����������next����2����������������Base Case����
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