/*
2909. Number Game medium 元素和最小的山形三元组 II
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
	// 解法一：枚举中间值
	int minimumSum(vector<int>& nums) {
		int res = INT_MAX, n = nums.size(), leftMin = nums[0];
		vector<int> rightMin(n);	// 有点类似DP
		rightMin[n - 1] = nums[n - 1];
		for (int i = n - 2; i >= 0; i--)
			rightMin[i] = min(nums[i], rightMin[i + 1]);
		
		for (int i = 1; i < n-1; i++) {
			leftMin = min(nums[i], leftMin);
			if (leftMin <nums[i] && rightMin[i+1]<nums[i])
				res = min(res, nums[i] + leftMin + rightMin[i+1]);
		}

		return res==INT_MAX ? -1 : res;
	}
};

int main() {
	Solution s;
	vector<int> nums = { 8,6,1,5,3 };
	cout << s.minimumSum(nums) << endl;
	return 0;
}