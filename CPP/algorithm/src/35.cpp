/*
35. Search Insert Position [Easy - 2]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) left = mid + 1;
			else right = mid - 1;
		}
		return left;
	}
};

int main() {
    Solution s;
	vector<int> nums = { 1,3,5,6 };
	int target = 2;
	cout << s.searchInsert(nums, target) << endl;
	return 0;
}