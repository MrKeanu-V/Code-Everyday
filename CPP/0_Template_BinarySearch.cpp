/*
	二分查找：
	1. 二分查找的前提是数组是有序的，才可依次二分查找范围。二分查找的关键在于left与right的更新，
	公式基本为mid = left + (right - left) / 2，在Base Case时left和right对应为mid的下一个位置。
	2. 每次查找将查找范围缩小一半，即二分。二分查找有三种写法：闭区间、左闭右开和开区间。
	3. 时间复杂度：O(logn)
	4. 空间复杂度：O(1)
	5. 二分查找在STL一般命名为low_bound和high_bound，分别表示大于等于和大于目标值的第一个位置。
	6. 二分查找的细节是或者说难点是二分查找的边界问题，即left和right的更新！
*/
//#include <bits/stdc++.h> // GNU C++ specific, not allowed in MSVC
#include <iostream>
#include <vector>
#include <queue>	// priority_queue
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

int lower_bound(vector<int>& nums, int target) {	// 闭区间
	int left = 0, right = (int)nums.size() - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] < target) left = mid + 1;	// 范围缩小到 [mid+1, right]
		else right = mid - 1;	// 范围缩小到 [left, mid-1]
	}
	return left;
}

int lower_bound2(vector<int>& nums, int target) {	// 左闭右开
	int left = 0, right = (int)nums.size();
	while (left < right) {	// 区间不能为空
		int mid = left + (right - left) / 2;	// 范围缩小到 [mid+1, right)
		if (nums[mid] < target) left = mid + 1;	// 范围缩小到 [left, mid)
		else right = mid;
	}
	return left; //	左右都可，结束结果为left==right
}

int lower_bound3(vector<int>& nums, int target) {	// 开区间
	int left = -1, right = (int)nums.size();
	while (left+1 < right) {
		int mid = left + (right - left) / 2;
		(nums[mid] < target) ? left = mid : right = mid;
	}
	return right;
}

// C++11 引入的STL库
int example(vector<int>& nums, int target) {
	int prePos = std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
	int nextPos = nums.end() - std::upper_bound(nums.begin(), nums.end(), target);
	return 0;
}

// C++20 引入ranges库， 包含上下二分和count_if、fileter、for_each、transform等函数
int example2(vector<int>& nums, int target) {
	//int prePos = std::ranges::lower_bound(nums, target) - nums.begin();
	//int nextPos = std::ranges::upper_bound(nums, target) - nums.begin();
	return 0;
}

