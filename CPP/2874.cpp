/*
2874. ������Ԫ���е����ֵ II medium
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
using namespace std;

class Solution {
public:
	// �ⷨһ�� ö���м似��+���ݷ�Χ����
	long long maxTripletValue(vector<int>& nums) {
		long long ans = 0;
		int leftMax = nums[0], n = nums.size();
		vector<int> rightMax(n, nums[n - 1]);

		for (int i = n - 2; i >= 0; i--) {
			rightMax[i] = max(rightMax[i + 1], nums[i]);
		}
		
		for (int i = 1; i < n - 1; i++) {
			ans = max(ans, (long long)((leftMax - nums[i])) * rightMax[i + 1]);
			leftMax = max(leftMax, nums[i]);
		}

		return ans;
	}
};

int main() {
	Solution sln;
	vector<int> nums = { 1000000,1,1000000 };
	cout << sln.maxTripletValue(nums) << endl;
	return 0;
}