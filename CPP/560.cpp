/*
560. Subarray Sum Equals K middle 和为K的子数组 中等
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	// 解法一：暴力法
	int subarraySum1(vector<int>& nums, int k) {
		int res = 0;
		
		for (int i = 0; i < nums.size(); i++) {
			int sum = 0;
			for (int j = i; j < nums.size(); j++){
				sum+=nums[j];
				if (sum == k) {
					res++;
				}
			}
		}

		return res;
	}

	//解法二：前缀和+哈希表
	int subarraySum(vector<int>& nums, int k) {
		int res = 0;
		vector<int> presum(nums.size()+1);
		unordered_map<int, int> indexMap;
		// 求前缀和
		for (int i = 0; i < nums.size(); i++) {
			presum[i+1] = presum[i] + nums[i];
		}
		
		for (int sum : presum) {
			if (indexMap.find(sum-k) != indexMap.end()) {
				res += indexMap[sum - k];
			}
			indexMap[sum]++;
		}
		
		return res;
	}
};

int main() {
	Solution s;
	vector<int> nums = { 1,2,3 };
	int k = 3;
	cout<<s.subarraySum(nums, k)<<endl;
	return 0;
}
