/*
45. Jump Game II [Medium - 6]
*/
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <numeric>
#include <ranges>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
	// 解法一：一维DP 时间复杂度O(nlogn) 空间复杂度O(n)
	int jump_1(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n, INT_MAX);
		dp[0] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= nums[i] && i + j < n; j++) {
				dp[i + j] = min(dp[i + j], dp[i] + 1);
			}
		}
		return dp[n - 1];
	}
	// 解法二：贪心 时间复杂度O(n) 空间复杂度O(1)
	int jump(vector<int>& nums) {
		int n = nums.size(), end = 0, maxPos = 0, steps = 0;
		for (int i = 0; i < n - 1; i++) {
			if (i <= maxPos) {
				maxPos = max(maxPos, nums[i] + i);
				if (i == end) {
					end = maxPos;
					steps++;
				}
			}
		}
		return steps;
	}
};

int main() {
	Solution sln;
	vector<int> nums = { 2,3,1,1,4 };
	cout << sln.jump(nums) << endl;
	return 0;
}