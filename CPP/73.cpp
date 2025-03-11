/*
73. Set Matrix Zeroes [Medium - 3]
*/
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <ranges>
#include <functional>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
	// 解法一 queue + 模拟
	void setZeroes_1(vector<vector<int>>& matrix) {
		queue<pair<int, int>> q;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[i].size(); j++) {
				if (matrix[i][j] == 0) q.push({ i,j });	// or make_pair(i,j)
			}
		}
		while (!q.empty()) {
			auto [x,y] = q.front();
			q.pop();
			for (int i = 0; i < matrix.size(); i++) matrix[i][y] = 0;
			for (int i = 0; i < matrix[0].size(); i++) matrix[x][i] = 0;
		}
	}
	// 解法二 原地
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		bool flag = false;
		for (int i = 0; i < m; i++) {
			if (matrix[i][0] == 0) flag = true;
			for (int j = 1; j < n; j++) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = matrix[0][j] = 0;
				}
			}
		}
		for (int i = m - 1; i >= 0; i--) {
			for (int j = 1; j < n; j++) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
			}
			if (flag) matrix[i][0] = 0;
		}
	}
};

//int main() {
//	Solution sln;
//	vector<vector<int>> nums = { {1, 2, 3}, {4, 0, 6}, {7, 8, 9} };
//	sln.setZeroes(nums);
//	for (auto& row : nums) {
//		for (auto& num : row)
//			cout << num << " ";
//		cout << endl;
//	}
//	return 0;
//}