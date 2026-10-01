/*
34. Find First and Last Position of Element in Sorted Array [Medium - 4]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <fnt/fnt_solution.h>
#include <fnt/fnt_utils.h>
using namespace fnt;
using namespace std;

class Solution34 : public BaseSolution {
private:
	int lowerBound(vector<int>& nums, int target) {
		int left = -1, right = (int)nums.size();
		while (left+1 < right) {
			int mid = left + (right - left) / 2;
			//(nums[mid] < target ? left : right) = mid;
			(nums[mid] < target) ? left = mid : right = mid;
		}
		return right;
	}
	int lowerBound1(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;	// 以左为边界
			if (nums[mid] < target) left = mid + 1;	// next=[mid+1,right]
			else right = mid - 1;	// next=[left,mid-1]
		}
		return left;
	}
	int lowerBound2(vector<int>& nums, int target) {
		int left = 0, right = (int)nums.size();
		while (left < right) {
			int mid = left + (right - left) / 2;	// 范围缩小到 [mid+1, right)
			if (nums[mid] < target) left = mid + 1;	// 范围缩小到 [left, mid)
			else right = mid;
		}
		return left;
	}
public:
	FNT_SOLUTION_KEY("34")
	// 二分查找 变体
	vector<int> searchRange(vector<int>& nums, int target) {
		int left = lowerBound(nums, target);
		if (left == nums.size() || nums[left] != target) return { -1,-1 };
		int right = lowerBound(nums, target + 1) - 1;
		return { left,right };
	}

	vector<int> searchRange2(vector<int>& nums, int target) {
		vector<int> res(2, -1);
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) left = mid + 1;
			else right = mid - 1;
		}
		if (left == nums.size() || nums[left] != target) return res;
		res[0] = left, left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target+1) left = mid + 1;
			else right = mid - 1;
		}
		res[1] = left - 1;
		return res;
	}

	void test() override {
		vector<int> nums = { 0,1,2,3,4,5,6,7,7,7,7,7,8,8,14 };
		int target = 7;
		vector<int> ans = searchRange(nums, target);
		cout << ans[0] << " " << ans[1] << endl;
	}
};

FNT_REGISTER(Solution34);