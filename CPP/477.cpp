/*
477. Total Hamming Distance [Medium - 4]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
	int hammingDistance(int x, int y) {
		int res = 0, s = x ^ y;
		while (s) {
			s &= s - 1;
			res++;
		}
		return res;
	}
	// �ⷨһ������ ��ʱ Time:O(n^2) Space:O(1)
	int totalHammingDistance_1(vector<int>& nums) {
		int res = 0, n = nums.size();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				res += hammingDistance(nums[i], nums[j]);
			}
		}
		return res;
	}
	// �ⷨ�� ��ѧ+λ���� Time:O(n) Space:O(1)
	int totalHammingDistance(vector<int>& nums) {
		int res = 0, n = nums.size();
		for (int i = 0; i < 30; i++) {
			int cnt = 0;
			for (auto x : nums) {
				cnt += (x >> i) & 1;
			}
			res+=cnt*(n-cnt);
		}
		return res;
	}
};