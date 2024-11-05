/*
10.01. Sorted Merge Icci [Esay]
*/
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
#include <numeric>
#include <functional>
#include <utility> // pair
using namespace std;

class Solution {
public:
	void merge1(vector<int>& A, int m, vector<int>& B, int n) {
		for (int i = 0; i < n; i++) A[m + i] = B[i];
		sort(A.begin(), A.end());
	}
	// 解法二 双指针
	void merge2(vector<int>& A, int m, vector<int>& B, int n) {
		vector<int> sorted(m + n);
		//int sorted[m + n];
		int p1 = 0, p2 = 0, cur;
		while (p1 < m || p2 < n) {
			if (p1 == m) {
				cur = B[p2++];
			}
			else if (p2 == n) {
				cur = A[p1++];
			}
			else if (A[p1] < B[p2]) {
				cur = A[p1++];
			}
			else cur = B[p2++];
			sorted[p1 + p2 - 1] = cur;
		}
		for (int i = 0; i < m + n; i++) A[i] = sorted[i];
	}
	// 解法三 双指针优化
	void merge(vector<int>& A, int m, vector<int>& B, int n) {
		int p1 = m - 1, p2 = n - 1, tail = m + n - 1, cur;
		while (p1 >= 0 || p2 >= 0) {
			if (p1 == -1) cur = B[p2--];
			else if (p2 == -1) cur = A[p1--];
			else if (A[p1] > B[p2]) cur = A[p1--];
			else cur = B[p2--];
			A[tail--] = cur;
		}
	}
};

int main() {
	Solution sln;
	vector<int> nums1 = { 1,2,3,0,0,0 }, nums2 = { 2,5,6 };
	sln.merge(nums1, 3, nums2, 3);
	for (int i = 0; i < nums1.size(); i++) cout << nums1[i] << " ";
	return 0;
}