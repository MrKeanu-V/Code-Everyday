/*
34. Find First and Last Position of Element in Sorted Array [Medium - 4]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
private:
	int lowerBound(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;	// 以左为边界
			if (nums[mid] < target) left = mid + 1;	// next=[mid+1,right]
			else right = mid - 1;	// next=[left,mid-1]
		}
		return left;
	}
public:
	// 二分查找 变体
	vector<int> searchRange1(vector<int>& nums, int target) {
		int left = lowerBound(nums, target);
		if (left == nums.size() || nums[left] != target) return { -1,-1 };
		int right = lowerBound(nums, target + 1) - 1;
		return { left,right };
	}

	vector<int> searchRange(vector<int>& nums, int target) {
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
};

int main() {
	Solution sln;
	vector<int> nums = { 0,1,2,3,4,5,6,7,7,7,7,7,8,8,14 };
	int target = 7;
	vector<int> ans = sln.searchRange(nums, target);
	cout << ans[0] << " " << ans[1] << endl;
	return 0;
}