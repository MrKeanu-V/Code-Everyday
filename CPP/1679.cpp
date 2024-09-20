/*
1679. Max Number of K-Sum Pairs medium K和数对的最大数目
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
	// 解法一：哈希表
	int maxOperations(vector<int>& nums, int k) {
		int res = 0;
		unordered_map<int, int> dic; // key:num, value:count

		for (int num:nums) {
			int need = k - num;
			if (dic.find(need) != dic.end()&&dic[need]>0)
				res++, dic[need]--;
			else
				dic[num]++;
		}

		return res;
	}
};

int main() {
	Solution sln;
	vector<int> nums = { 1,2,3,4 };
	int k = 5;
	cout << sln.maxOperations(nums, k) << endl;
	return 0;
}