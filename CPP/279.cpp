/*
279. Perfect Squares [Medium - 4]
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <numeric>
#include <ranges>
using namespace std;

int memo[101][10001];

auto init = []() {
	memset(memo, -1, sizeof(memo));
	return 0;
}();

int dfs(int i, int j) {
	if (i == 0) return j == 0 ? 0 : INT_MAX;

	int& res = memo[i][j];
	if (res != -1) return res;

	if (j < i * i) res = dfs(i - 1, j);
	else res = min(dfs(i - 1, j), dfs(i, j - i * i) + 1);

	return res;
}

class Solution {
public:
	//Solution() {
	//	init();
	//}
	// 解法一 DP
	int numSquares1(int n) {
		vector<int> dp(n + 1, INT_MAX);
		dp[1] = 1, dp[0] = 0;
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j * j <= i; j++) {
				dp[i]= min(dp[i], dp[i - j * j] + 1);
			}
		}
		return dp[n];
	}
	// 解法二 数学 四平方和定理
	int numSquares2(int n) {
		function<bool(int)> isSquare = [](int x) { return pow((int)sqrt(x), 2) == x; };
		function<bool(int)> check4 = [](int x) {
			while (x % 4 == 0) x /= 4;
			return x % 8 == 7;
		};

		if (isSquare(n)) return 1;
		if (check4(n)) return 4;

		for (int i = 1; i * i <= n; i++) {
			if (isSquare(n - i * i)) return 2;
		}

		return 3;
	}
	// 解法三 完全背包+记忆化搜索
	int numSquares3(int n) {
		return dfs(sqrt(n), n);
	}
	// 解法三 完全背包+空间优化
	int numSquares(int n) {
		vector<int> dp(n + 1);
		for(int i=0; i<=n; i++) dp[i] = i;
		for (int i = 2, j = i * i; j <= n; i++, j = i * i) {
			for (int k = j; k <= n; k++) {
				dp[k] = min(dp[k], dp[k - j] + 1);
			}
		}
		return dp[n];
	}
};

int main() {
	Solution sln;
	int n = 32;
	cout << sln.numSquares(n) << endl;
	return 0;
}