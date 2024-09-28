/*
LCR 068. 搜索插入位置 [Easy]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
using namespace std;

class Solution {
public:
	// 解法一 暴力
	int serchInsert1(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] >= target)
				return i;
				
		return nums[nums.size() - 1] < target ? nums.size() : 0;
	}
	// 解法二 二分查找
	int serchInsert(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + ((right - left) >> 1);
			if (nums[mid] >= target) {
				if (mid == 0 || nums[mid - 1] < target)
					return mid;
				right = mid - 1;
			}
			else 
				left = mid + 1;
		}
		return nums.size();
	}
};

int main() {
	vector<int> nums = { 1,3,5,6 };
	int target = 2;
	Solution sln;
	cout << sln.serchInsert(nums, target) << endl;
	return 0;
}