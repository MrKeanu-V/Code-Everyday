/*
215. Kth Largest Element in an Array [Medium - 6]
*/
#include "pub_template.h"
using namespace std;

class Solution {
public:
	// 解法一 优先队列最大堆 Time: O(nlogk) Space: O(k)
	int findKthLargest_1(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, less<int>> maxHeap;	// 用法：less<int>表示最大堆，top()为最大值；greater<int>表示最小堆，top()为最小值
		for(int num:nums) maxHeap.push(num);
		while (--k) maxHeap.pop();
		return maxHeap.top();
	}
	// 解法二 快速选择 Time: O(n) Space: O(1)
	int findKthLargest(vector<int>& nums, int k) {
		return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
	}
	int quickSelect(vector<int>& nums, int l, int r, int k) {
		if (l == r) return nums[l];
		int p = partition(nums, l, r);
		if (p == k) return nums[p];
		else if (p < k) return quickSelect(nums, p + 1, r, k);
		else return quickSelect(nums, l, p - 1, k);
	}
	int partition(vector<int>& nums, int l, int r) {
		int pivot = nums[r], i = l;
		for (int j = l; j < r; ++j) {
			if (nums[j] <= pivot) swap(nums[i++], nums[j]);
		}
		swap(nums[i], nums[r]);
		return i;
	}
};