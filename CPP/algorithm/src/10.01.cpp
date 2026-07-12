/**
@Author: MrKeanu
@Date: 2026-07-12
@Description: Leetcode 10.01. Sorted Merge LCCI [Easy]
@History: Original creation — brute force + two-pointer solutions.
*/
#include "fnt_utils.h"
#include "fnt_solution.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using namespace fnt;

// 注意：文件名含点号，C++ 类名不能含点，用 Solution10_01 代替
class Solution10_01 : public BaseSolution {
public:
    FNT_SOLUTION_KEY("10.01")

	void merge1(vector<int>& A, int m, vector<int>& B, int n) {
		for (int i = 0; i < n; i++) A[m + i] = B[i];
		sort(A.begin(), A.end());
	}

	// 解法二 双指针
	void merge2(vector<int>& A, int m, vector<int>& B, int n) {
		vector<int> sorted(m + n);
		int p1 = 0, p2 = 0, cur;
		while (p1 < m || p2 < n) {
			if (p1 == m) {
				cur = B[p2++];
			}
			else if (p2 == n) {
				cur = A[p1++];
			}
			else if (A[p1] < B[p2]) {
				cur = A[p1++];
			}
			else cur = B[p2++];
			sorted[p1 + p2 - 1] = cur;
		}
		for (int i = 0; i < m + n; i++) A[i] = sorted[i];
	}

	// 解法三 双指针优化（从后往前）
	void merge(vector<int>& A, int m, vector<int>& B, int n) {
		int p1 = m - 1, p2 = n - 1, tail = m + n - 1, cur;
		while (p1 >= 0 || p2 >= 0) {
			if (p1 == -1) cur = B[p2--];
			else if (p2 == -1) cur = A[p1--];
			else if (A[p1] > B[p2]) cur = A[p1--];
			else cur = B[p2--];
			A[tail--] = cur;
		}
	}

    void test() override {
        vector<int> nums1 = { 1,2,3,0,0,0 }, nums2 = { 2,5,6 };
        merge(nums1, 3, nums2, 3);
        printVector1D(nums1);    // [1, 2, 2, 3, 5, 6]
    }
};

FNT_REGISTER(Solution10_01);