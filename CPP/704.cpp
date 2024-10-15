/*
704. Binary Search [Esay - 2]
*/
//#include <bits/stdc++.h> // GNU C++ specific, not allowed in MSVC
#include <iostream>
#include <vector>
#include <queue>	// priority_queue
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

/*
	���ֲ��ң�
	1. ���ֲ��ҵ�ǰ��������������ģ��ſ����ζ��ֲ��ҷ�Χ�����ֲ��ҵĹؼ�����left��right�ĸ��£�
	��ʽ����Ϊmid = left + (right - left) / 2����Base Caseʱleft��right��ӦΪmid����һ��λ�á�
	2. ÿ�β��ҽ����ҷ�Χ��Сһ�룬�����֡����ֲ���������д���������䡢����ҿ������ұպͿ����䡣
   	3. ʱ�临�Ӷȣ�O(logn)
   	4. �ռ临�Ӷȣ�O(1)
*/
class Solution {
public:
	// �ⷨһ ���ֲ���
	int search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) return mid;
			else if (nums[mid] > target) right = mid - 1;
			else left = mid + 1;
		}
		return -1;
	}
};

int main() {
	Solution sln;
	vector<int> nums = { 1,2,3,4,5,6,7,8,9,10 };
	cout << sln.search(nums, 5) << endl;
	return 0;
}