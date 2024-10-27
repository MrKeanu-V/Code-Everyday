/*
120. Triangle [Medium - 4]
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
	int minimumTotal1(vector<vector<int>>& triangle) {
		int m = triangle.size(), res = INT_MAX;
		vector<vector<int>> dp(m, vector<int>(m, INT_MAX));
		dp[0][0] = triangle[0][0];
		for(int i=1;i<m;++i) 
			for (int j = 0; j <= i; ++j) {
				//dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
				if (j != 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + triangle[i][j]);
				if (j != i) dp[i][j] = min(dp[i][j], dp[i - 1][j] + triangle[i][j]);
			}
		return *min_element(dp[m - 1].begin(), dp[m - 1].end());
	}
	// 滚动数组 DP空间优化
	int minimumTotal2(vector<vector<int>>& triangle) {
		int m = triangle.size(), res = INT_MAX;
		vector<vector<int>> dp(2, vector<int>(m, INT_MAX));
		dp[0][0] = triangle[0][0];
		for (int i = 1; i < m; ++i) {
			for (int j = i; j >= 0; --j) {
				if (j == i) dp[i&1][j] = dp[(i - 1) & 1][j - 1] + triangle[i][j];
				else if (j == 0) dp[i&1][j] = dp[(i - 1) & 1][j] + triangle[i][j];
				else dp[i&1][j] = min(dp[(i - 1) & 1][j], dp[(i - 1) &1][j - 1]) + triangle[i][j];
			}
		}
		return *min_element(dp[(m - 1) & 1].begin(), dp[(m - 1)&1].end());
	}
	// 自底向上+滚动数组
	int minimumTotal(vector<vector<int>>& triangle) {
		int m = triangle.size();
		vector<int> dp(m + 1);
		for (int i = m - 1; i >= 0; --i)
			for (int j = 0; j <= i; ++j)
				dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
		return dp[0];
	}
};

int main() {
	Solution sln;
	vector<vector<int>> triangle = { {2},{3,4},{6,5,7},{4,1,8,3} };
	cout << sln.minimumTotal(triangle) << endl;
	return 0;
}