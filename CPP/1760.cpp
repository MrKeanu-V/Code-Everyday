/*
1760. Minimum Limit of Balls in a Bag [Medium - 1760]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
	int minimumSize(vector<int>& nums, int maxOperations) {
		function<bool(int)> isSatisfied = [&](int limit)->bool {
			long long cost = 0;
			for (auto num : nums) cost += (num - 1) / limit;
			return cost <= maxOperations;
		};
		int left = 1, right = *max_element(nums.begin(), nums.end());
		while (left <= right) {
			int mid = left + (right - left) / 2;
			isSatisfied(mid) ? right = mid - 1 : left = mid + 1;
		}
		return left;
	}
};

int main() {
	Solution sln;
	vector<int> nums = { 2,4,8,2 };
	int maxOperations = 4;
	cout << sln.minimumSize(nums, maxOperations) << endl;
	return 0;
}