/*
215. Kth Largest Element in an Array [Medium - 6]
*/
#include "fnt/fnt_solution.h"
#include "fnt/fnt_utils.h"
using namespace std;
using namespace fnt;

class Solution215 : public BaseSolution {
public:
    FNT_SOLUTION_KEY("215")
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

	void test() override {
		// 注意：两种解法都会修改入参，每个用例使用独立副本
		vector<int> nums1 = { 3, 2, 1, 5, 6, 4 };
		cout << findKthLargest(nums1, 2) << endl;      // 5

		vector<int> nums2 = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
		cout << findKthLargest(nums2, 4) << endl;      // 4

		vector<int> nums3 = { 3, 2, 1, 5, 6, 4 };
		cout << findKthLargest_1(nums3, 2) << endl;    // 5（解法一 对照）
	}
};

FNT_REGISTER(Solution215);
