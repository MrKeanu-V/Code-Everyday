/*
209. Minimum Size Subarray Sum middle ������С��������
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	// �ⷨһ�������� TLE
	int minSubArrayLen1(int target, vector<int>& nums) {
		int res = 0;

		for (int i = 0; i < nums.size(); i++) {
			int sum = 0;
			for (int j = i; j < nums.size(); j++) {
				sum += nums[j];
				if (sum >= target) {
					res = res == 0 ? (j - i + 1) : min(res, j - i + 1);
					break;
				}
			}
		}

		return res;
	}
	// �ⷨ����ǰ׺��
	int minSubArrayLen2(int target, vector<int>& nums) {
		int res = 0;
		vector<int> prefix(nums.size() + 1, 0);
		prefix[0] = 0;
		for (int i = 0; i < nums.size(); i++) {
			prefix[i + 1] = prefix[i] + nums[i];
			int left = 0;
			while (prefix[i + 1] - prefix[left] >= target) {
				res = res == 0 ? (i - left + 1) : min(res, i - left + 1);
				left++;
			}
		}

		return res;
	}
	// �ⷨ����ǰ׺�� + ���ֲ���(Ϊ���ҹ��̼���)
	int minSubArrayLen3(int target, vector<int>& nums) {
		int res = INT_MAX, n = nums.size();
		vector<int> prefix(n + 1, 0);
		for(int i=0;i<n;i++) prefix[i+1] = prefix[i] + nums[i];
		
		for (int i = 1; i < prefix.size(); i++) {
			int need = target + prefix[i - 1];
			auto it = lower_bound(prefix.begin(), prefix.end(), need);
			if (it != prefix.end())
				res = min(res, it - prefix.begin() - i + 1);
		}

		return res == INT_MAX ? 0 : res;
	}
    // �ⷨ�ģ���������
	int minSubArrayLen(int target, vector<int>& nums) {
		int res = INT_MAX, n = nums.size();
		int left = 0, right = 0, sum = 0;

		while (right < n) {
			sum += nums[right];
			while (sum >= target) {
				res = min(res, right - left + 1);
				sum -= nums[left];
				left++;
			}
			right++;
		}

		return res == INT_MAX ? 0 : res;
	}
};

int main() {
	Solution s;
	vector<int> nums = { 2,3,1,2,4,3 };
	int target = 7;
	cout << s.minSubArrayLen(target, nums) << endl;
	return 0;
}