/*
74. Search a 2D Matrix [Medium - 3]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
	// 解法一 二分查找 Time:O(logn) Space:O(1)
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) return false;
		int m = matrix.size(), n = matrix[0].size();
		int l = 0, r = m * n - 1;
		while (l <= r) {
			int mid = (r + l)>>1;
			int val = matrix[mid / n][mid % n];
			if (val == target) return true;
			(val < target) ? l = mid + 1 : r = mid - 1;
		}
		return false;
	}
	// 解法二 两次二分查找 Time:O(logmn) Space:O(1)
	bool searchMatrix_01(vector<vector<int>> matrix, int target) {
		auto row = upper_bound(matrix.begin(), matrix.end(), target, [](const int b, const vector<int>& a) {
			return b < a[0];
			});
		if (row == matrix.begin()) {
			return false;
		}
		--row;
		return binary_search(row->begin(), row->end(), target);
	}

	// 解法二 排除法 
	bool searchMatrix_02(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) return false;
		int m = matrix.size(), n = matrix[0].size();
		int row = 0, col = n - 1;
		while (row < m && col >= 0) {
			if (matrix[row][col] == target) return true;
			if (matrix[row][col] > target) col--;
			else row++;
		}
		return false;
	}

	void test() {
		vector<vector<int>> matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,60} };
		cout << searchMatrix(matrix, 3) << endl;
		cout << searchMatrix(matrix, 13) << endl;
		cout << searchMatrix(matrix, 1) << endl;
		cout << searchMatrix(matrix, 60) << endl;
		cout << searchMatrix(matrix, -10) << endl;
		cout << searchMatrix(matrix, 80) << endl;
	}
};

//int main() {
//	Solution().test();
//	return 0;
//}