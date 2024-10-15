/*
	二分查找：
	1. 二分查找的前提是数组是有序的，才可依次二分查找范围。二分查找的关键在于left与right的更新，
	公式基本为mid = left + (right - left) / 2，在Base Case时left和right对应为mid的下一个位置。
	2. 每次查找将查找范围缩小一半，即二分。二分查找有三种写法：闭区间、左闭右开和开区间。
	3. 时间复杂度：O(logn)
	4. 空间复杂度：O(1)
	5. 二分查找在STL一般命名为low_bound和high_bound，分别表示大于等于和大于目标值的第一个位置。
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
	while (left <= right) {
		int mid = left + (right - left) / 2;	// 范围缩小到 [mid+1, right)
		if (nums[mid] < target) left = mid + 1;	// 范围缩小到 [left, mid)
		else right = mid;
	}
	return left;
}

int lower_bound3(vector<int>& nums, int target) {	// 开区间
	int left = 0, right = (int)nums.size();
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] < target) left = mid;	// 范围缩小到 (mid, right)
		else right = mid;	// 范围缩小到 (left, mid)
	}
	return left;
}
