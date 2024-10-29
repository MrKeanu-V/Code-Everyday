/*
1289. Minimum Falling Path Sum II [Hard - 1697]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
using namespace std;

class Solution {
public:
	int minFallingPathSum1(vector<vector<int>>& grid) {
		int n = grid.size();
		vector<vector<int>> dp(n + 1, vector<int>(n + 2, INT_MAX));
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				for (int k = 1; k <= n; ++k)
					if (k != j && dp[i - 1][k] < dp[i][j]) dp[i][j] = dp[i - 1][k];
				dp[i][j] = grid[i - 1][j - 1] + (dp[i][j] == INT_MAX ? 0 : dp[i][j]);
			}
		return *min_element(dp[n].begin(), dp[n].end());
	}
	// 状态转移方程优化
	int minFallingPathSum(vector<vector<int>>& grid) {
		int n = grid.size(), sum1st = 0, sum2nd = 0, min_index = -1;
		for (int i = 0; i < n; i++) {
			int cur_sum1st = INT_MAX, cur_sum2nd = INT_MAX, cur_min1st = -1;
			for (int j = 0; j < n; j++) {
				int cur_sum = (j != min_index ? sum1st : sum2nd) + grid[i][j];
				if (cur_sum < cur_sum1st) cur_sum2nd = cur_sum1st, cur_sum1st = cur_sum, cur_min1st = j;
				else if (cur_sum < cur_sum2nd) cur_sum2nd = cur_sum;
			}
			sum1st = cur_sum1st, sum2nd = cur_sum2nd, min_index = cur_min1st;
		}
		return sum1st;
	}
};

int main() {
	Solution sln;
	vector<vector<int>> grid = { { 1,2,3 }, { 4,5,6 }, { 7,8,9 } };
	cout << sln.minFallingPathSum(grid) << endl;
	return 0;
}