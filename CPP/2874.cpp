/*
2874. 有序三元组中的最大值 II medium
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
using namespace std;

class Solution {
public:
	// 解法一： 枚举中间技巧+数据范围限制
	long long maxTripletValue(vector<int>& nums) {
		long long ans = 0;
		int leftMax = nums[0], n = nums.size();
		vector<int> rightMax(n, nums[n - 1]);

		for (int i = n - 2; i >= 0; i--) {
			rightMax[i] = max(rightMax[i + 1], nums[i]);
		}
		
		for (int i = 1; i < n - 1; i++) {
			ans = max(ans, (long long)((leftMax - nums[i])) * rightMax[i + 1]);
			leftMax = max(leftMax, nums[i]);
		}

		return ans;
	}
};

int main() {
	Solution sln;
	vector<int> nums = { 1000000,1,1000000 };
	cout << sln.maxTripletValue(nums) << endl;
	return 0;
}