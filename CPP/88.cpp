/*
88. Merge Sorted Array [Easy - 2]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
	// 解法一 暴力 Time:O(m+n) Space:O(m+n)
	void merge_01(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> tmp = nums1;
		for (int i = 0, j = 0, k = 0; k < m + n; ++k) {
			if (i == m) {
				tmp[k] = nums2[j];
				j++;
			}
			else if (j == n) {
				tmp[k] = nums1[i];
				i++;
			}
			else if (nums1[i] < nums2[j]) {
				tmp[k] = nums1[i];
				i++;
			}
			else {
				tmp[k] = nums2[j];
				j++;
			}
		}
		nums1 = tmp;
	}
	// 解法一优化 双指针 Time:O(m+n) Space:O(1)
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i = m + n - 1, j = m - 1, k = n - 1; k >= 0; --i) {
			if (j >= 0 && nums1[j] > nums2[k]) 
				nums1[i] = nums1[j--];
			else 
				nums1[i] = nums2[k--];
		}
	}
	void test() {
		vector<int> nums1 = { 1,3,5,0,0,0 };
		vector<int> nums2 = {2,3,7};
		merge(nums1, 3, nums2, 3);
		print1DVector(nums1);
	}
};

//int main() {
//	Solution().test();
//	return 0;
//}