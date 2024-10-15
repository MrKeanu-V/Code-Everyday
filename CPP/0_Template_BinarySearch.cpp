/*
	���ֲ��ң�
	1. ���ֲ��ҵ�ǰ��������������ģ��ſ����ζ��ֲ��ҷ�Χ�����ֲ��ҵĹؼ�����left��right�ĸ��£�
	��ʽ����Ϊmid = left + (right - left) / 2����Base Caseʱleft��right��ӦΪmid����һ��λ�á�
	2. ÿ�β��ҽ����ҷ�Χ��Сһ�룬�����֡����ֲ���������д���������䡢����ҿ��Ϳ����䡣
	3. ʱ�临�Ӷȣ�O(logn)
	4. �ռ临�Ӷȣ�O(1)
	5. ���ֲ�����STLһ������Ϊlow_bound��high_bound���ֱ��ʾ���ڵ��ںʹ���Ŀ��ֵ�ĵ�һ��λ�á�
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

int lower_bound(vector<int>& nums, int target) {	// ������
	int left = 0, right = (int)nums.size() - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] < target) left = mid + 1;	// ��Χ��С�� [mid+1, right]
		else right = mid - 1;	// ��Χ��С�� [left, mid-1]
	}
	return left;
}

int lower_bound2(vector<int>& nums, int target) {	// ����ҿ�
	int left = 0, right = (int)nums.size();
	while (left <= right) {
		int mid = left + (right - left) / 2;	// ��Χ��С�� [mid+1, right)
		if (nums[mid] < target) left = mid + 1;	// ��Χ��С�� [left, mid)
		else right = mid;
	}
	return left;
}

int lower_bound3(vector<int>& nums, int target) {	// ������
	int left = 0, right = (int)nums.size();
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] < target) left = mid;	// ��Χ��С�� (mid, right)
		else right = mid;	// ��Χ��С�� (left, mid)
	}
	return left;
}
