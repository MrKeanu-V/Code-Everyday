/*
√Ê ‘Ã‚ 16.19. Pond Sizes Icci
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
private:
	int row, col;
	vector<vector<int>> dirs = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
	int dfs(vector<vector<int>>& land, int i, int j) {
		if (i < 0 || i >= row || j < 0 || j >= col || land[i][j]) return 0;
		land[i][j] = 1;
		int size = 1;
		for (auto& dir : dirs) {
			size += dfs(land, i + dir[0], j + dir[1]);
		}
		return size;
		//return dfs(land, i - 1, j - 1) + dfs(land, i - 1, j) + dfs(land, i - 1, j + 1) + dfs(land, i, j + 1) + dfs(land, i, j - 1) + dfs(land, i + 1, j - 1) + dfs(land, i + 1, j) + dfs(land, i + 1, j + 1) + 1;
	}
public:
	vector<int> pondSizes(vector<vector<int>>& land) {
		vector<int> res;
		row = land.size(), col = land[0].size();
		for(int i=0;i<row;i++)
			for (int j = 0; j < col; j++) {
				if (!land[i][j]) {
					res.push_back(dfs(land, i, j));
				}
			}
		sort(res.begin(), res.end());
		return res;
	}
};

int main() {
	Solution sln;
	vector<vector<int>> land = { {0,2,1,0},{0,1,0,1},{1,1,0,1},{0,1,0,1} };
	vector<int> sizes = sln.pondSizes(land);
	for (auto& size : sizes) cout << size << " ";
	return 0;
}
