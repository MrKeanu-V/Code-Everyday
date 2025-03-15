/*
215. Kth Largest Element in an Array [Medium - 6]
*/
#include "pub_template.h"
using namespace std;

class Solution {
public:
	// �ⷨһ ���ȶ������� Time: O(nlogk) Space: O(k)
	int findKthLargest_1(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, less<int>> maxHeap;	// �÷���less<int>��ʾ���ѣ�top()Ϊ���ֵ��greater<int>��ʾ��С�ѣ�top()Ϊ��Сֵ
		for(int num:nums) maxHeap.push(num);
		while (--k) maxHeap.pop();
		return maxHeap.top();
	}
	// �ⷨ�� ����ѡ�� Time: O(n) Space: O(1)
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