/*
220. Contains Duplicate III [Hard - 6]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
	// �ⷨһ �������� + ģ�� Time:O(nk) Space:O(k)
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
	// �ⷨ�� �������� + ���򼯺� Time:O(nlogk) Space:O(k)
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
	// �ⷨ�� Ͱ���� �������� Time:O(n) Space:O(min(n, k))
	bool containsNearbyAlmostDuplicate_3(vector<int>& nums, int indexDiff, int valueDiff) {
		int n = nums.size(), i = 0;
		unordered_map<int, int> window;
		auto getBucketId = [&](int x) { return x < 0 ? (x + 1ll) / (valueDiff + 1ll) - 1 : x / (valueDiff + 1ll); };
		while (i < n) {
			int id = getBucketId(nums[i]);
			if (window.count(id)) return true;
			if (window.count(id - 1) && nums[i] - window[id - 1] <= valueDiff) return true;
			if (window.count(id + 1) && window[id + 1] - nums[i] <= valueDiff) return true;
			window[id] = nums[i++];
			if (window.size() > indexDiff) window.erase(getBucketId(nums[i - indexDiff - 1]));
		}
		return false;
	}
};