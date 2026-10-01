/*
35. Search Insert Position [Easy - 2]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <fnt/fnt_solution.h>
#include <fnt/fnt_utils.h>
using namespace fnt;
using namespace std;

class Solution35 : public BaseSolution {
public:
	FNT_SOLUTION_KEY("35")
	int searchInsert(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) left = mid + 1;
			else right = mid - 1;
		}
		return left;
	}

	void test() override {
		vector<int> nums = { 1,3,5,6 };
		int target = 2;
		cout << searchInsert(nums, target) << endl;
	}
};

FNT_REGISTER(Solution35);
