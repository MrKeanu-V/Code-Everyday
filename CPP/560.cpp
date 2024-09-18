/*
560. Subarray Sum Equals K middle ��ΪK�������� �е�
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
	// �ⷨһ��������
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

	//�ⷨ����ǰ׺��+��ϣ��
	int subarraySum(vector<int>& nums, int k) {
		int res = 0;
		vector<int> presum(nums.size()+1);
		unordered_map<int, int> indexMap;
		// ��ǰ׺��
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
