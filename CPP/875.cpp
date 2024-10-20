/*
875. Koko Eating Bananas [Medium - 1766]
*/
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <ranges>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

/*
如何判断一道题是否可以使用二分查找？
1. 二分查找通常用于在有序数组中查找一个数或范围
2. 二分查找通常需要满足以下条件：1. 目标函数单调性；2. 存在上下界；3. 能够通过索引访问
*/

class Solution {
public:
	// 解法一 二分查找 // 此类题目为建模题，需要将问题转化为二分查找问题
	int minEatingSpeed1(vector<int>& piles, int h) {
		function<long long(long long)> timeCost = [&](long long speed) {
			long long time = 0;
			for (long long pile : piles) time += pile / speed + (pile % speed != 0);	//向上取整：(a-1)/b+1
			return time;
		};
		long long left = 1, right = *max_element(piles.begin(), piles.end());
		while (left <= right) {
			long long mid = left + (right - left) / 2;
			if (timeCost(mid) > h) left = mid + 1;
			else right = mid - 1;
		}
		return left;
	}
	// 解法一 二分查找修改
	int minEatingSpeed(vector<int>& piles, int h) {
		function<bool(long long)> isUnSatisfied = [&](long long speed)->bool {
			long long time = 0;
			for (long long pile : piles) time += (pile - 1) / speed + 1;
			return time > h;
		};
		long long left = 1, right = *max_element(piles.begin(), piles.end());
		while (left <= right) {
			long long mid = left + (right - left) / 2;
			isUnSatisfied(mid) ? left = mid + 1 : right = mid - 1;
		}
		return left;
	}
};

int main() {
	Solution sln;
	vector<int> piles = { 3,6,7,11 };
	int h = 8;
	cout << sln.minEatingSpeed(piles, h) << endl;
	return 0;
}