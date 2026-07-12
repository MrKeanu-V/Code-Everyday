/*
LCS 01. JuXwi Download Plugins [Esay]
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <utility>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
	// 解法一 模拟
	int leastMinutes1(int n) {
		return ceil(log(n)/log(2)) + 1;
	}
	int leastMinutes2(int n) {
		return n <= 1 ? 1 : log(n - 1) / log(2) + 2;
	}
	// 解法二 DP
	int leastMinutes(int n) {
		vector<int> dp(n + 1, 0);
		dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			dp[i] = dp[(i + 1) / 2] + 1;
		}
		return dp[n];
	}
};

int main() {
	Solution sln;
	int n = 69;
	cout << sln.leastMinutes(n) << endl;
	return 0;
}