/*
930. Binary Subarrays With Sum middle ����ͬ�Ķ�Ԫ������
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	// �ⷨһ��������
	int numSubarraysWithSum1(vector<int>& nums, int goal) {
		int res=0;

		for (int i = 0; i < nums.size(); i++) {
			int sum = 0;
			for (int j = i; j < nums.size(); j++) {
				sum += nums[j];
				if (sum == goal)
					res++;
			}
		}

		return res;
	}
	// �ⷨ����ǰ׺��+��ϣ��
	int numSubarraysWithSum(vector<int>& nums, int goal) {
		int res = 0, n = nums.size();
		vector<int> preSum(n + 1, 0);
		unordered_map<int, int> preSumCount;	// key:presum value:count
		preSumCount[0] = 1;
		for (int i = 0; i < n; i++) {
			preSum[i + 1] = preSum[i] + nums[i];
		}
		for (int i = 1; i < n + 1; i++) {
			auto it = preSumCount.find(preSum[i] - goal);
			if (it != preSumCount.end()) {
				res += it->second;
			}
			preSumCount[preSum[i]]++;
		}

		return res;
	}
};

int main() {
	Solution s;
	vector<int> nums = { 0,0,0,0,0 };	//{ 1,0,1,0,1 };
	int goal = 0;	// 2;
	cout<<s.numSubarraysWithSum(nums, goal)<<endl;
	return 0;
}