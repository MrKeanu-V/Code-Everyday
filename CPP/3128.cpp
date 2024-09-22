/*
3128. 直角三角形 中等
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> //枚举相关库，如accumulate、inner_product、adjacent_difference、partial_sum、transform_reduce、reduce等
using namespace std;

class Solution {
public:
	// 解法一：枚举
	long long numberOfRightTriangles(vector<vector<int>>& grid) {
		long long res = 0;
		int m = grid.size(), n = grid[0].size();
		vector<int> colSum(n, 0), rowSum(m, 0);

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				rowSum[i] += grid[i][j];
				colSum[j] += grid[i][j];
			}

		for (int i = 0; i < m; i++) 
			for (int j = 0; j < n; j++)
				if (grid[i][j] == 1)
					res += (rowSum[i] - 1) * (colSum[j] - 1);


		return res;
	}
};

int main() {
	Solution sln;
   	vector<vector<int>> grid = { {0,1,0},{0,1,1},{0,1,0} };
	vector<int> grid2 = { 1,1,1 };
	int sum = accumulate(grid2.begin(), grid2.end(), 0);
	cout << sum << endl;
	cout << sln.numberOfRightTriangles(grid) << endl;
	return 0;
}
