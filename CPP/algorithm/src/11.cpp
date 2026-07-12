/**
@Author: MrKeanu
@Date: 2026-07-12
@Description: Leetcode 11. Container With Most Water [Medium]
@History: Original creation — brute force + two-pointer solutions.
*/
#include "fnt_utils.h"
#include "fnt_solution.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using namespace fnt;

class Solution11 : public BaseSolution {
public:
    FNT_SOLUTION_KEY("11")

	// 解法一：暴力法 必定超时
	int maxArea1(vector<int>& height) {
		int maxRes = 0;
		for (int i = 0; i < height.size(); i++) {
			for (int j = i + 1; j < height.size(); j++) {
				maxRes = max(maxRes, min(height[i], height[j]) * ((j - i)));
			}
		}
		return maxRes;
	}

	// 解法二：双指针
	int maxArea(vector<int>& height) {
		int maxRes = 0, left = 0, right = height.size() - 1;

		while (left < right) {
			maxRes = max(maxRes, min(height[left], height[right]) * (right - left));
			if (height[left] < height[right]) {
				left++;
			}
			else {
				right--;
			}
		}

		return maxRes;
	}

    void test() override {
        vector<int> height = { 1,8,6,2,5,4,8,3,7 };
        cout << maxArea(height) << endl;     // 49
        height = { 1,1 };
        cout << maxArea(height) << endl;     // 1
    }
};

FNT_REGISTER(Solution11);