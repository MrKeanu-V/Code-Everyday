/*
64. Minimum Path Sum [Medium - 4]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include <numeric>
#include <functional>
using namespace std;

class Solution {
public:
	// ¬∑æ∂Œ Ã‚ DP
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
		for(int i=1;i<=m;++i)
			for (int j = 1; j <= n; ++j)
				dp[i][j] = grid[i - 1][j - 1] + (min(dp[i - 1][j], dp[i][j - 1]) == INT_MAX ? 0 : min(dp[i - 1][j], dp[i][j - 1]));
		return dp[m][n];
	}
};

int main() {
	Solution sln;
	vector<vector<int>> grid = { {1,3,1},{1,5,1},{4,2,1} };
	cout << sln.minPathSum(grid) << endl;
	return 0;
}