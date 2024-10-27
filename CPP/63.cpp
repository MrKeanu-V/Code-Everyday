/*
63. Unique Paths II [Medium - 4]
*/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges>
#include <numeric> // accumulate
#include <limits>
#include <functional>
using namespace std;

class Solution {
public:
	// 路径问题，求不同路径数时用动态规划，求最短路径时用BFS
	int uniquePathsWithObstacles2(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j)
				dp[i][j] = obstacleGrid[i - 1][j - 1] ? 0 : i == 1 && j == 1 ? 1 : dp[i - 1][j] + dp[i][j - 1];
		return dp[m][n];
	}
	// 滚动数组思想进行动态规划优化
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		vector<int> dp(n, 0);
		dp[0] = !obstacleGrid[0][0];
		// 滚动数组
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				obstacleGrid[i][j] ? dp[j] = 0 : (j >= 1 && !obstacleGrid[i][j - 1]) ? dp[j] += dp[j - 1] : 0;
		return dp.back();
	}
};

int main() {
	Solution sln;
	vector<vector<int>> obstacleGrid = { {0,0,0},{0,1,0},{0,0,0} };
	cout << sln.uniquePathsWithObstacles(obstacleGrid) << endl;
	return 0;
}