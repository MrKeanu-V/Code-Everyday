/*
2835. Minimum Operations to Form Subsequence with Target Sum [Hard - 2207]
*/
#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <functional>
#include <numeric>	// 包含accumulate求和函数
#include <iterator>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
	int minOperations1(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end(), less<int>());
		int n = nums.size(), res = 0;
		long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        // base case
		if (sum < target) return -1;
		priority_queue<int> heap(nums.begin(), nums.end());
		while (target) {
			int num = heap.top();
			heap.pop();
			if (sum - num >= target) sum -= num;
			else if (num <= target) target -= num, sum -= num;
			else {
				heap.push(num >> 1);
				heap.push(num >> 1);
				res++;
			}
		}
		return res;
	}
	int minOperations2(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end(), less<int>());
		int n = nums.size(), res = 0;
		long long sum = accumulate(nums.begin(), nums.end(), 0LL);
		if (sum < target) return -1;
		while (target) {
			int num = nums.back();
			nums.pop_back();
			if (sum - num >= target) sum -= num;
			else if (num <= target) target -= num, sum -= num;
			else {
				nums.push_back(num >> 1);
				nums.push_back(num >> 1);
				res++;
			}
		}
		return res;
	}
};

int main() {
	Solution sln;
	vector<int> nums = { 1,2,8 };
	int target = 7;
	cout << sln.minOperations(nums, target) << endl;
	return 0;
}