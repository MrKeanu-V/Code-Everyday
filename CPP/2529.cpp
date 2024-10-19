/*
2529. Maximum Count of Positive Integer and Negative Integer [Easy - 1196]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
//#include <bits/stdc++.h>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <ranges> // C++20新引入的库，在包含二分查找算法lower_bound、upper_bound、count_if等函数
using namespace std;

class Solution {
private:
	int lowerBound(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) left = mid + 1;
			else right = mid - 1;
		}
		return left;
	}
public:
	// 解法一 二分查找
	int maximumCount1(vector<int>& nums) {
		return max(lowerBound(nums, 0), (int)nums.size() - lowerBound(nums, 1));
	}
	// 解法二 暴力
	int maximumCount2(vector<int>& nums) {
		int pos = 0, neg = 0;
		for (auto& num : nums) {
			if (num < 0) neg++;
			if (num > 0) pos++;
		}
		return max(pos, neg);
	}
	// 解法三 使用ranges库
	//int maximumCount3(vector<int>& nums) {
	//	int pos = nums.count_if(nums, [](int x) {return x > 0; });
	//	int neg = nums.count_if(nums, [](int x) {return x < 0; });
	//	return max(pos, neg);
	//}
	// 解法四 使用STL的lower_bound函数
	int maximumCount4(vector<int>& nums) {
		int pos = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
		int neg = nums.end() - lower_bound(nums.begin(), nums.end(), 1);
		return max(pos, neg);
	}
	// 解法五 使用STL的count_if函数
	int maximumCount(vector<int>& nums) {
		int pos = std::count_if(nums.begin(), nums.end(), [](int x) { return x > 0; });
		int neg = std::count_if(nums.begin(), nums.end(), [](int x) { return x < 0; });
		return max(pos, neg);
	}
};

int main() {
	Solution sln;
	vector<int> nums = { -2, -1, 0,0,0,0,1 };
	cout << sln.maximumCount(nums) << endl;
	return 0;
}