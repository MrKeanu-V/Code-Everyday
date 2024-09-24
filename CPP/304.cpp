/*
304. Range Sum Query 2D - Immutable medium
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
using namespace std;


// 解法一：二维前缀和
class NumMatrix {
private:
   	vector<vector<int>> dp2D;

public:
	NumMatrix(vector<vector<int>>& matrix) {
		int n = matrix.size(), m = matrix[0].size();
		dp2D.resize(n + 1, vector<int>(m + 1, 0));

		// 计算二维前缀和
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= m; j++) 
				dp2D[i][j] = dp2D[i - 1][j] + dp2D[i][j - 1] - dp2D[i - 1][j - 1] + matrix[i - 1][j - 1];

	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return dp2D[row2 + 1][col2 + 1] - dp2D[row2 + 1][col1] - dp2D[row1][col2 + 1] + dp2D[row1][col1];
	}
};

int main() {
	vector<vector<int>> matrix = { {3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5} };
    NumMatrix numMatrix(matrix);
    cout << numMatrix.sumRegion(2, 1, 4, 3) << endl;	// 8
	cout << numMatrix.sumRegion(1, 1, 2, 2) << endl;
   	cout << numMatrix.sumRegion(1, 2, 2, 4) << endl;
	return 0;
}