/*
1283. Find the Smallest Divisor Given a Threshold [Medium - 1542]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <functional>	// ����std::function����ָ�룬std::hash��
using namespace std;

class Solution {
public:
	// �ⷨһ ������ֲ���
	int smallestDivisor1(vector<int>& nums, int threshold) {
		sort(nums.begin(), nums.end());
		function<int(int)> getSum = [&](int divisor) {
			int sum = 0;
			for (int num : nums) sum += (num + divisor - 1) / divisor;
			return sum;
		};
		int left = 1, right = nums.back();
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (getSum(mid) <= threshold) right = mid - 1;
			else left = mid + 1;
		}
		return left;
	}
	// �ⷨ�� �Ż�
	int smallestDivisor2(vector<int>& nums, int threshold) {
		function<int(int)> getSum = [&](int divisor) {
			int sum = 0;
			for (int num : nums) sum += (num + divisor - 1) / divisor;
			return sum;
		};
		int left = 1, right = *max_element(nums.begin(), nums.end());
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (getSum(mid) <= threshold) right = mid - 1;
			else left = mid + 1;
		}
		return left;
	}
	// �ⷨ�� �����
	int smallestDivisor(vector<int>& nums, int threshold) {
		function<int(int)> getSum = [&](int divisor) {
			int sum = 0;
			for (int num : nums) sum += (num + divisor - 1) / divisor;	// ����ȡ�� (a + b - 1) / b ���� a / b + (a % b > 0 ? 1 : 0) ���� a / b + (a % b != 0);
			return sum;
		};
		int left = 1, right = *max_element(nums.begin(), nums.end());
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (getSum(mid) <= threshold) right = mid - 1;
			else left = mid + 1;
		}
		return left;
	}
};

int main() {
	Solution sln;
	vector<int> nums = { 1,2,5,9 };
	int threshold = 6;
	cout << sln.smallestDivisor(nums, threshold) << endl;
	return 0;
}