/*
740. Delete and Earn [Medium - 5]
*/
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <climits>
#include <cmath>
#include <queue>
#include <algorithm>
#include <numeric>
#include <ranges>
using namespace std;

class Solution {
public:
	int deleteAndEarn(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size(), m = nums.back();
		vector<int> dp(m + 1, 0);
		for (int i = 0; i < n; i++) {
			dp[nums[i]]++;
		}
		for (int i = 2; i <= m; i++) {
			dp[i] = max(dp[i - 1], dp[i] * i + dp[i - 2]);
		}
		return dp[m];
	}
};

int main() {
	Solution sln;
	vector<int> nums = { 3,4,2 };
	cout << sln.deleteAndEarn(nums) << endl;
	return 0;
}