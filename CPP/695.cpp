/*
695. Max Area of Island [Medium - 4]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

// 网格图题型
class Solution {
private:
	int dfs1(vector<vector<int>>& grid, int i, int j) {
		if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || !grid[i][j]) return 0;
		grid[i][j] = 0;
		return dfs(grid, i - 1, j) + dfs(grid, i + 1, j) + dfs(grid, i, j - 1) + dfs(grid, i, j + 1) + 1;
	}
	// dirs优化
	vector<vector<int>> dirs = { {0,1},{0,-1},{1,0},{-1,0} };
	int dfs(vector<vector<int>>& grid, int i, int j) {
		if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || !grid[i][j]) return 0;
		grid[i][j] = 0;
		int area = 1;
		for (auto& dir : dirs)
			area += dfs(grid, i + dir[0], j + dir[1]);
		return area;
	}
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int maxArea = 0;
		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[0].size(); j++)
				maxArea = max(maxArea, dfs(grid, i, j));
		return maxArea;
	}
	// BFS
	int maxAreaOfIsland2(vector<vector<int>>& grid) {
		int maxArea = 0, m = grid.size(), n = grid[0].size();
		queue<pair<int, int>> q;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (!grid[i][j]) continue;
				q.push({ i,j });
				int area = 0;
				grid[i][j] = 0;
				while (!q.empty()) {
					auto [x, y] = q.front();
					area++, q.pop();
					if (x - 1 >= 0 && grid[x - 1][y]) q.push({ x - 1,y }), grid[x - 1][y] = 0;
					if (x + 1 < m && grid[x + 1][y]) q.push({ x + 1,y }), grid[x + 1][y] = 0;
					if (y - 1 >= 0 && grid[x][y - 1]) q.push({ x,y - 1 }), grid[x][y - 1] = 0;
					if (y + 1 < n && grid[x][y + 1]) q.push({ x,y + 1 }), grid[x][y + 1] = 0;
				}
				maxArea = max(maxArea, area);
			}
		}
		return maxArea;
	}
};

int main() {
	Solution sln;
    vector<vector<int>> grid = { {1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1} };
	cout<<sln.maxAreaOfIsland(grid)<<endl;
	return 0;
}