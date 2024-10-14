/*
1091. Shortest Path in Binary Matrix [Medium - 1658]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>	// 包含 priority_queue
#include <functional> // 包含greater
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
//#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	vector<vector<int>> dirs = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 },{ 1,1 },{ 1,-1 },{ -1,1 },{ -1,-1 } };
public:
	// 解法一 BFS 可改A*，时间复杂度O(n^2)，空间复杂度O(n^2) 双向BFS
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		if (grid[0][0]||grid.back().back()) return -1;	// grid[row-1][col-1]==1
		int res = -1, row = grid.size(), col = grid[0].size();
		queue<pair<int, int>> q;
		q.push({ 0,0 });
		grid[0][0] = 1;
		// base case | next case
		while (!q.empty()) {
			auto [x, y] = q.front();
			q.pop(), res += 1;
			// base case
			if (x == row - 1 && y == col - 1)  return -1;
			// next case
			for (auto& dir : dirs) {
				int dx = x + dir[0], dy = y + dir[1];
				if (dx >= 0 && dx < row && dy >= 0 && dy < col && !grid[dx][dy])
					q.push({ dx,dy }), grid[dx][dy] = 1;
			}
		}

		return -1;
	}

	int shortestPathBinaryMatrix2(vector<vector<int>>& grid) {
		int row = grid.size(), col = grid[0].size();
		if (grid[0][0] || grid.back().back()) return -1;
		vector<vector<int>> visited(row, vector<int>(col, INT_MAX));
		queue<pair<int, int>> q;
		q.push({ 0,0 }), visited[0][0] = 1;
		while (!q.empty()) {
			auto [x, y] = q.front();
			q.pop();
			// base case
			if (x == row - 1 && y == col - 1) return visited[x][y];
			// next case
			for (auto& dir : dirs) {
				int dx = x + dir[0], dy = y + dir[1];
				// base case 必须为visited[dx][dy] <= visited[x][y] + 1可能有潜在路径
				if (dx < 0 || dx >= row || dy < 0 || dy >= col || grid[dx][dy] || visited[dx][dy] <= visited[x][y] + 1) continue;
				q.push({ dx,dy }), visited[dx][dy] = visited[x][y] + 1;
			}
		}

		return -1;
	}
};

int main() {
	Solution sln;
	vector<vector<int>> grid = { { 0,0,0  },{1,1,0}, { 1, 1,0 } };
	cout << sln.shortestPathBinaryMatrix(grid) << endl;
	return 0;
}