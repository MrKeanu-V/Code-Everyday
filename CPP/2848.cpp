/*
2848 - Points That Intersect With Cars eazy
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
	// 解法一：暴力法
	int numberOfPoints1(vector<vector<int>>& nums) {
		int maxSize = 0, res = 0;
		for (auto& num : nums)
			maxSize = max(maxSize, num[1]);
		
		vector<int> count(maxSize + 1, 0);
		for (int i = 0; i < nums.size(); i++)
			for (int j = nums[i][0]; j <= nums[i][1]; j++)
				count[j]=1;

		for (auto num : count)
			res += num;
		return res;
	}

	// 解法二：差分数组
	int numberOfPoints(vector<vector<int>>& nums) {
		int maxSize = 0, res = 0, count = 0;
		for (auto& num : nums)
			maxSize = max(maxSize, num[1]);
		vector<int> diff(maxSize + 2, 0);
		for (auto& num : nums) {
			diff[num[0]]++;
			diff[num[1] + 1]--;
		}
		for (int i = 1; i <= maxSize; i++) {
			count += diff[i];
			if (count)
				res++;
		}
		return res;
	}
};

int main() {
    Solution sln;
	vector<vector<int>> nums = { {3,6},{1,5},{4,7} };	// return 7
    cout << sln.numberOfPoints(nums);
	return 0;
}
