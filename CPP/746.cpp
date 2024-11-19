/*
746. Min Cost Climbing Stairs [Easy - 1358]
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
#include <functional>
using namespace std;

class Solution {
public:
	// �ⷨһ DP
	int minCostClimbingStairs(vector<int>& cost) {
		vector<int> dp(cost.size() + 1, 0);
		dp[1] = cost[0], dp[2] = cost[1];
		for (int i = 2; i <= cost.size(); i++) {
			dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i-1];
		}
		return min(dp[cost.size() - 1], dp[cost.size()]);
	}
};

int main() {
	Solution sln;
	vector<int> cost = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
	cout << sln.minCostClimbingStairs(cost) << endl;
	return 0;
}