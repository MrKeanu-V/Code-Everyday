/*
931. Minimum Falling Path Sum [Medium - 1573]
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <functional>
#include <ranges>
using namespace std;

class Solution {
public:
	// 二维DP
	int minFallingPathSum1(vector<vector<int>>& matrix) {
		int m = matrix.size();
		vector<vector<int>> dp(m, vector<int>(m+2, INT_MAX));
		for(int i = 1; i <= m; ++i) dp[0][i]= matrix[0][i-1];
		for (int i = 1; i < m; ++i)
			for (int j = 1; j <= m; ++j)
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1])) + matrix[i][j - 1];
		return *min_element(dp[m-1].begin(), dp[m-1].end());
	}
	// 二维DP2
	int minFallingPathSum2(vector<vector<int>>& matrix) {
		int m = matrix.size();
		vector<vector<int>> dp(m, vector<int>(m, INT_MAX));
		dp[0] = matrix[0];
		for (int i = 1; i < m; ++i)
			for (int j = 0; j < m; ++j) {
				dp[i][j] = dp[i - 1][j] + matrix[i][j];
				if (j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + matrix[i][j]);
				if (j < m - 1) dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + matrix[i][j]);
			}
		return *min_element(dp[m - 1].begin(), dp[m - 1].end());
	}
	// 滚动数组优化
	int minFallingPathSum(vector<vector<int>>& matrix) {
		int m = matrix.size();
		vector<int> dp(m + 2, INT_MAX);
		for (int i = 0; i < m; ++i) dp[i + 1] = matrix[0][i];
		for (int i = 1; i < m; ++i) {
			int prev = dp[0];
			for (int j = 0; j < m; j++) {
				int tmp = prev;
				prev=dp[j+1];
				dp[j + 1] = min({ tmp, dp[j + 1], dp[j + 2] }) + matrix[i][j];
			}
		}
		return *min_element(dp.begin(), dp.end());
	}
	
};

int main() {
	Solution sln;
	vector<vector<int>> matrix = { {100,-42,-46,-41}, {31,97,10,-10},{-58,-51,82,89},{51,58,69,-51} }; // -36
	cout << sln.minFallingPathSum(matrix) << endl;
	return 0;
}