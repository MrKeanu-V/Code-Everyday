/*
3070. 元素和小于等于k的子矩阵数目 medium
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
using namespace std;

class Solution {
public:
	// 解法一：二维前缀和 modal
	int countSubmatrices(vector<vector<int>>& grid, int k) {
		int ans = 0, m = grid.size(), n = grid[0].size();
		vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));	// 多开一行一列，方便计算

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + grid[i-1][j-1];
				if (sum[i][j] <= k)
					ans++;
			}
		}

		return ans;
	}
};

int main() {
	Solution sln;
	vector<vector<int>> grid = { {7,6,3}, {6,6,1} };
	int k = 18;
	cout << sln.countSubmatrices(grid, k) << endl;
	return 0;
}
