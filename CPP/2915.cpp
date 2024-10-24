/*
2915. Length of Longest Subsequence that Sums to Target [Medium - 1659]
*/
#include <iostream>
#include <vector>
#include <algorithm> // std::sort
#include <numeric> // std::accumulate
#include <functional> // std::bind std::greater 
#include <limits> // std::numeric_limits
using namespace std;

class Solution {
public:
	// 解法一 一维01背包
	int lenghtOfLongestSubsequence1(vector<int>& nums, int target) {
		vector<int> dp(target + 1, INT_MIN);
		dp[0] = 0;
		int sum = 0;
		for (int num : nums) {
			sum = min(sum + num, target);
			for (int i = sum; i >= num; --i) dp[i] = max(dp[i], dp[i - num] + 1);
		}
		return dp[target] > 0 ? dp[target] : -1;
	}
	// 解法二 二维01背包 WA
	int lenghtOfLongestSubsequence(vector<int>& nums, int target) {
		int n = nums.size();
		vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= target; ++j)
				dp[i][j] = nums[i-1] <= j ? max(dp[i-1][j], dp[i-1][j - nums[i-1]] + 1) : dp[i-1][j];
		return dp[n][target] > 0 ? dp[n][target] : -1;
	}
};

int main() {
	Solution sln;
	vector<int> nums = { 1, 2, 3, 4, 5 };
	int target = 9;
	cout << sln.lenghtOfLongestSubsequence(nums, target) << endl;
	return 0;
}
