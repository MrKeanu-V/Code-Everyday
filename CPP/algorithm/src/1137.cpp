/*
1137. N-th Tribonacci Number [Easy - 1143]
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <ranges>
#include <utility>
#include <climits>
#include <cmath>
#include <queue>
#include <functional>
using namespace std;

int memo[101];

auto init = []() {
	memset(memo, -1, sizeof(memo));
	memo[0] = 0, memo[1] = 1, memo[2] = 1;
	return 0;
}();

class Solution {
public:
	// 解法一 记忆化+dp
	int tribonacci(int n) {
		if (n <= 0) return 0;
		if (memo[n] != -1) return memo[n];
		memo[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
		return memo[n];
	}
	// 解法二 递推
	int tribonacci2(int n) {
		if (n <= 0) return 0;
		if (n <= 2) return 1;
		return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
	}
};

int main() {
	Solution sln;
	int n = 25;
	cout << sln.tribonacci(n) << endl;
	return 0;
}