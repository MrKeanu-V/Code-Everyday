/*
219. Contains Duplicate II easy
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	// 解法一：暴力法 TLE
	bool containsNearbyDuplicate1(vector<int>& nums, int k) {
		for (int i = 0; i < nums.size(); i++)
			for (int j = i + 1; j < nums.size(); j++)
				if (nums[i] == nums[j] && abs(i - j) <= k)
					return true;

		return false;
	}
	// 解法二：哈希表
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int> dic;

		for (int i = 0; i < nums.size(); i++) {
			if (dic.count(nums[i])&&i-dic[nums[i]]<=k) {
				return true;
			}
			dic[nums[i]] = i;
		}

		return false;
	}
};

int main() {
	vector<int> nums = { 1,2,3,1,2,3 };
	int k = 2;
	cout<<Solution().containsNearbyDuplicate(nums, k)<<endl;
	return 0;
}