/*
477. Total Hamming Distance [Medium - 4]
*/
#include "fnt/fnt_solution.h"
#include "fnt/fnt_utils.h"
using namespace fnt;

class Solution477 : public BaseSolution {
public:
    FNT_SOLUTION_KEY("477")

	int hammingDistance(int x, int y) {
		int res = 0, s = x ^ y;
		while (s) {
			s &= s - 1;
			res++;
		}
		return res;
	}
	// 解法一：暴力 超时 Time:O(n^2) Space:O(1)
	int totalHammingDistance_1(vector<int>& nums) {
		int res = 0, n = nums.size();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				res += hammingDistance(nums[i], nums[j]);
			}
		}
		return res;
	}
	// 解法二 数学+位运算 Time:O(n) Space:O(1)
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

	void test() override {
		vector<int> nums = { 4,14,2 };
		cout << totalHammingDistance(nums) << endl;    // 6
		nums = { 4,14,4 };
		cout << totalHammingDistance(nums) << endl;    // 4
	}
};

FNT_REGISTER(Solution477);