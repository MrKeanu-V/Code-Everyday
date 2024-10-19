/*
1385. Find the Distance Value Between Two Arrays [Easy - 1235]
*/
#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <queue>
//#include <bits/stdc++.h>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;

class Solution {
private:
	int lowerBound(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) left = mid + 1;
			else right = mid - 1;
		}
		return left;
	}
public:
	// 解法一 暴力法
	int findTheDistanceValue1(vector<int>& arr1, vector<int>& arr2, int d) {
		auto findDistance = [&](int x) {
			for (auto& i : arr2)
				if (abs(x - i) <= d) return false;
			return true;
		};
		return count_if(arr1.begin(), arr1.end(), findDistance);
	}
	// 解法二 二分法+排序
	int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
		sort(arr2.begin(), arr2.end());
		auto findDistance = [&](int x) {
			int m = min(x - d, x + d), n = max(x - d, x + d);
			auto it = lower_bound(arr2.begin(), arr2.end(), m);
			if (it != arr2.end() && *it <= n) return false;
			return true;
		};
		return count_if(arr1.begin(), arr1.end(), findDistance);
	}
};

int main() {
	Solution sln;
	vector<int> arr1 = { 2,1,100,3 }, arr2 = { -5,-2,10,-3,7 };
	int d = 6;
	cout << sln.findTheDistanceValue(arr1, arr2, d) << endl;
	return 0;
}