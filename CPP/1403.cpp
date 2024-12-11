/*
1403. Minimum Subsequence in Non-Increasing Order [Easy - 1288]
*/
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <functional>
#include <ranges>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
	// 解法一 贪心 + 模拟
	vector<int> minSubsequence_1(vector<int>& nums) {
		sort(nums.begin(), nums.end(), greater<int>());
		vector<int> ans;

		for (int i = 0; i < nums.size(); i++) {
			ans.push_back(nums[i]);
			if (accumulate(ans.begin(), ans.end(), 0) > accumulate(nums.begin() + i + 1, nums.end(), 0)) break;
		}

		return ans;
	}
	// 解法二 前缀和
	vector<int> minSubsequence_2(vector<int>& nums) {
		sort(nums.begin(), nums.end(), greater<int>());
		vector<int> presum(nums.size() + 1, 0);
		for (int i = 1; i < presum.size(); i++) presum[i] = presum[i - 1] + nums[i - 1];
		int index = 0;
		while (presum[index + 1] <= presum[presum.size() - 1] - presum[index + 1]) index++;
		return vector<int>(nums.begin(), nums.begin() + index + 1);
	}
	// 解法三 前缀和优化
	vector<int> minSubsequence(vector<int>& nums) {
		sort(nums.begin(), nums.end(), greater<int>());
		int sum = accumulate(nums.begin(), nums.end(), 0);
		for (int i = 0, presum=0; i < nums.size(); i++) {
			presum += nums[i];
			if (sum - presum < presum) return vector<int>(nums.begin(), nums.begin() + i + 1);
		}
	}
};

int main() {
	Solution sln;
	vector<int> nums = { 4,3,10,9,8 };
	vector<int> ans = sln.minSubsequence(nums);
	for (auto& i : ans) cout << i << " ";
	return 0;
}