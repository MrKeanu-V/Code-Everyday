/*
62. Unique Paths [Medium - 4]
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
	// DP中的路径问题
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j)
				dp[i][j] = i == 1 && j == 1 ? 1 : dp[i - 1][j] + dp[i][j - 1];
		return dp[m][n];
	}
};

int main() {
	Solution sln;
	int m = 1, n = 1;
	cout << sln.uniquePaths(m, n) << endl;
	return 0;
}