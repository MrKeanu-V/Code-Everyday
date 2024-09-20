/*
1512. Number of Good Pairs easy
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	// 解法一 暴力法
	int numIdenticalPairs1(vector<int>& nums) {
		int res = 0;

		for (int i = 0; i < nums.size(); i++)
			for (int j = i + 1; j < nums.size(); j++)
				if (nums[i] == nums[j])
					res++;

		return res;
	}
	// 解法二 哈希表
	int numIdenticalPairs(vector<int>& nums) {
		unordered_map<int, int> m;
		int res = 0;
		for (int num : nums)
			m[num]++;
		for ( auto & it : m) {
			res += it.second * (it.second - 1) / 2;
		}
		return res;
	}
};

int main() {
	Solution sln;
	vector<int> nums = { 1,2,3,1,1,3 };
	cout << sln.numIdenticalPairs(nums) << endl;
	return 0;
}