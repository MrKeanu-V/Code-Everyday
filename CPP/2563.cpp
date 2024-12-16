/*
2563. Count the Number of Fair Pairs [Medium - 1721]
*/
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
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

class Solution {
public:
	// 解法一 排序 + 二分
	long long countFairPairs_1(vector<int>& nums, int lower, int upper) {
		sort(nums.begin(), nums.end());
		long long res = 0;
		for (int i = 0; i < nums.size(); i++)
			res += upper_bound(nums.begin(), nums.begin() + i, upper - nums[i]) - lower_bound(nums.begin(), nums.begin() + i, lower - nums[i]);
		return res;
	}
	// 解法二 三指针
	long long countFairPairs(vector<int>& nums, int lower, int upper) {
		sort(nums.begin(), nums.end());
		long long res = 0;
		int l=nums.size(), r = nums.size();
		for (int i = 0; i < nums.size(); i++) {
			while (r && nums[r - 1] > upper - nums[i]) r--;
			while (l && nums[l - 1] >= lower - nums[i]) l--;
			res += min(r, i) - min(l, i);
		}
		return res;
	}
};

int main() {
	Solution sln;
	vector<int> nums = { 0,0,0,0,0,0 };
	int lower = 0, upper = 1;
	cout << sln.countFairPairs(nums, lower, upper) << endl;
	return 0;
}