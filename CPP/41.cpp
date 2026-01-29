/*
41. First Missing Positive [Hard - 7]
*/
#include "fnt_template.h"
#include "fnt_solution.h"
using namespace fnt;

class Solution41 {
public:
	// Solution 1: Hash Table, O(n) time, O(1) space
	int firstMissingPositive(vector<int>& nums) {
		int len = nums.size();
		for (int i = 0; i < len; ++i)
			// must be in [1, len], otherwise will be out of range
			// and this must need while loop, because there may is a number in [1,len], but is not appropriate with its index
			while (nums[i] > 0 && nums[i] <= len && nums[nums[i] - 1] != nums[i]) swap(nums[i], nums[nums[i] - 1]);
		for (int idx = 0; idx < len; ++idx) if (nums[idx] != idx + 1) return idx + 1;
		return len + 1;
	}

	void test() {
		vector<int> nums = { 1, 2, 0 };
		cout << firstMissingPositive(nums) << endl;
		nums = { 3, 4, -1, 1 };
		cout << firstMissingPositive(nums) << endl;
		nums = { 7, 8, 9, 11, 12 };
		cout << firstMissingPositive(nums) << endl;
	}
};

// RAII Register template
struct Solution41Register {
	Solution41Register() {
		Solution41 s;
		RegisterSolution("41", [&s]() { s.test(); });
	}
};

static Solution41Register __reg41;