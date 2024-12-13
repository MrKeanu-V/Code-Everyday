/*
2320. Count Number of Ways to Place Houses [Medium - 1608]
*/
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges>
#include <numeric>
#include <functional>
#include <climits>
#include <cmath>
using namespace std;

constexpr int MOD = 1e9 + 7, N = 1e4 + 4;
int dp[N] = { 1,2 };
int init = []() {
	for (int i = 2; i < N; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	return 0;
}();

class Solution {
public:
	// 解法一 线性DP
	int countHousePlacements_1(int n) {
		int mod = pow(10, 9) + 7;
		vector<long long> dp(n + 1, 1);
		dp[1] = 2;
		for (int i = 2; i <= n; i++) {
			dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
		}
		return dp[n] * dp[n] % mod;
	}
	// 解法一 优化
	int countHousePlacements(int n) {
		return (long long)dp[n] * dp[n] % MOD;
	}
};

int main() {
	Solution sln;
	cout << sln.countHousePlacements(1000) << endl;
	return 0;
}