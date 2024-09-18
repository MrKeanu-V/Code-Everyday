/*
303. Range Sum Query - Immutable simple 区域和检索-数组不可变 简单
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class NumArray {
public:
	vector<int> prefix;
	NumArray(vector<int>& nums) {
		//prefix.resize(nums.size() + 1);
		prefix.push_back(0);
		for (int i = 0; i < nums.size(); i++)
			//prefix[i+1]=prefix[i]+nums[i];
        	prefix.push_back(prefix.back()+nums[i]);
	}

	int sumRange(int left, int right) {
		return prefix[right + 1] - prefix[left];
	}

};

int main() {
	vector<int> nums = { -2, 0, 3, -5, 2, -1 };
	NumArray na(nums);
	cout << na.sumRange(0, 2) << endl;
	cout << na.sumRange(2, 5) << endl;
	cout << na.sumRange(0, 5) << endl;
	return 0;
}