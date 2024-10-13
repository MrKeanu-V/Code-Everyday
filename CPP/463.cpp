/*
463. Island Perimeter [Easy - 4]
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
	// 解法一 BFS
	int islandPerimeter2(vector<vector<int>>& grid) {
		int perimeter = 0, m = grid.size(), n = grid[0].size();
		queue<pair<int,int>> cur;
		vector<vector<int>> visited(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] && !visited[i][j]) {
					cur.push({ i,j }), visited[i][j] = 1;
					while (!cur.empty()) {
						auto [x, y] = cur.front();
						cur.pop();
						if (x - 1 >= 0 && grid[x - 1][y]) {
							if (!visited[x - 1][y])
								cur.push({ x - 1,y }), visited[x - 1][y] = 1;
							perimeter--;
						}
						if (x + 1 < m && grid[x + 1][y]) {
							if (!visited[x + 1][y])
								cur.push({ x + 1,y }), visited[x + 1][y] = 1;
							perimeter--;
						}
						if (y - 1 >= 0 && grid[x][y - 1]) {
							if (!visited[x][y - 1])
								cur.push({ x,y - 1 }), visited[x][y - 1] = 1;
							perimeter--;
						}
						if (y + 1 < n && grid[x][y + 1]) {
							if (!visited[x][y + 1])
								cur.push({ x,y + 1 }), visited[x][y + 1] = 1;
							perimeter--;
						}
						perimeter += 4;
					}
					return perimeter;
				}
			}
		}
		return perimeter;
	}

	// 解法二 迭代
	int dir[4][2] = { {0,-1},{0,1},{1,0},{-1,0} };
	int islandPerimeter(vector<vector<int>>& grid) {
		int perimeter = 0, row = grid.size(), col = grid[0].size();
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (grid[i][j]) {
					int cnt = 0;
					for (int k = 0; k < 4; k++) {
						int x = i + dir[k][0], y = j + dir[k][1];
						if (x < 0 || y < 0 || x >= row || y >= col || !grid[x][y])
							cnt++;
					}
					perimeter += cnt;
				}
			}
		}
		return perimeter;
	}
};

int main() {
	Solution sln;
	vector<vector<int>> grid = { {0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0} };
	cout << sln.islandPerimeter(grid) << endl;
	return 0;
}