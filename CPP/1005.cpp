/*
1005. Maximize Sum Of Array After K Negations [Easy - 1275]
*/
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>	// std::sort, std::reverse
#include <numeric>	// std::accumulate
#include <ranges>	// std::ranges::sort
#include <functional>
using namespace std;

class Solution {
public:
	// 解法一 排序 + 贪心
	int largestSumAfterKNegations_1(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end(), less<int>());
		while (k) {
			nums[0] = -nums[0];
			sort(nums.begin(), nums.end(), less<int>());
			k--;
		}
		return accumulate(nums.begin(), nums.end(), 0);
	}
	// 解法二 方法一优化
	int largestSumAfterKNegations(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end(), less<int>());
		int len = nums.size(), minIndex = 0;
		while (k) {
			nums[minIndex] = -nums[minIndex];
			k--;
			if (minIndex<len - 1 && nums[minIndex] > nums[minIndex + 1]) minIndex++;
		}
		return accumulate(nums.begin(), nums.end(), 0);
	}
};

int main() {
	Solution sln;
	vector<int> nums = { 4, 2, 3 };
	int k = 1;
	cout << sln.largestSumAfterKNegations(nums, k) << endl;
	return 0;
}