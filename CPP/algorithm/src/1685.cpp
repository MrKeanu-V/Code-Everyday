/*
1685. Sum of Absolute Differences in a Sorted Array [Medium] Score:1496
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;

// 数学推导
class Solution {
public:
	// 解法一：暴力模拟 TLE
	vector<int> getSumAbsoluteDifferences1(vector<int>& nums) {
		vector<int> res;

		for (int i = 0; i < nums.size(); i++) {
			int sum = 0;
			for (int j = 0; j < nums.size(); j++) {
				sum += abs(nums[i] - nums[j]);
			}
			res.emplace_back(sum);
		}

		return res;
	}
	// 解法二：前缀和
	vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
		int n = nums.size();
		vector<int> prefix(n + 1, 0), sufix(n + 1, 0);

		for (int i = 0; i < n; i++) {
			prefix[i+1] = prefix[i] + nums[i];
			sufix[n - i - 1] = sufix[n - i] + nums[n - i - 1];
		}
		for (int i = 0; i < n; i++)
			nums[i] = nums[i] * (i + 1) - prefix[i + 1] + sufix[i + 1] - nums[i] * (n - i - 1);

		return nums;
	}
};

int main() {
	Solution sln;
	vector<int> nums = { 1,4,6,8,10 };	// 递增
	vector<int> res = sln.getSumAbsoluteDifferences(nums);
	for(auto& e:res)
		cout<<e<<" ";
	return 0;
}