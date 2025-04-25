/*
220. Contains Duplicate III [Hard - 6]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
	// 解法一 滑动窗口 + 模拟 Time:O(nk) Space:O(k)
	bool containsNearbyAlmostDuplicate_1(vector<int>& nums, int indexDiff, int valueDiff) {
		int n = nums.size(), i = 1;
		deque<int> window = { nums[0] };
		while (i < n) {
			if (window.size() > indexDiff) window.pop_front();
			for (auto& x : window) if (abs(x - nums[i]) <= valueDiff) return true;
			window.push_back(nums[i++]);
		}
		return false;
	}
	// 解法二 滑动窗口 + 有序集合 Time:O(nlogk) Space:O(k)
	bool containsNearbyAlmostDuplicate_2(vector<int>& nums, int indexDiff, int valueDiff) {
		int n = nums.size(), i = 1;
		set<int> window = { nums[0] };
		while (i < n) {
			if (window.size() > indexDiff) window.erase(nums[i - indexDiff - 1]);
			auto it = window.lower_bound(nums[i] - valueDiff);
			if (it != window.end() && *it <= nums[i] + valueDiff) return true;
			window.insert(nums[i++]);
		}
		return false;
	}
};