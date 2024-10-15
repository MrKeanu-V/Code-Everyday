/*
704. Binary Search [Esay - 2]
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

/*
	二分查找：
	1. 二分查找的前提是数组是有序的，才可依次二分查找范围。二分查找的关键在于left与right的更新，
	公式基本为mid = left + (right - left) / 2，在Base Case时left和right对应为mid的下一个位置。
	2. 每次查找将查找范围缩小一半，即二分。二分查找有三种写法：闭区间、左闭右开、左开右闭和开区间。
   	3. 时间复杂度：O(logn)
   	4. 空间复杂度：O(1)
*/
class Solution {
public:
	// 解法一 二分查找
	int search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) return mid;
			else if (nums[mid] > target) right = mid - 1;
			else left = mid + 1;
		}
		return -1;
	}
};

int main() {
	Solution sln;
	vector<int> nums = { 1,2,3,4,5,6,7,8,9,10 };
	cout << sln.search(nums, 5) << endl;
	return 0;
}