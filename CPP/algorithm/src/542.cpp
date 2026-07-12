/*
542. 01 Matrix [Medium - 4]
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <numeric>
#include <functional>
#include <utility>
using namespace std;

class Solution {
private:
	static constexpr int dirs[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
public:
	// 解法一 BFS+记忆化 逆向
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
		int m = mat.size(), n = mat[0].size();
		queue<pair<int, int>> q;
		vector<vector<int>> dist(m, vector<int>(n));
		vector<vector<bool>> seen(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (mat[i][j] == 0) {
					dist[i][j] = 0;
					q.push(make_pair(i, j));
					seen[i][j] = true;
				}
			}
		}

		// BFS
		while (!q.empty()) {
			auto [i, j] = q.front();
			q.pop();
			for (auto dir : dirs) {
				int next_i = i + dir[0], next_j = j + dir[1];
				if (next_i >= 0 && next_i < m && next_j >= 0 && next_j < n && !seen[next_i][next_j]) {
					dist[next_i][next_j] = dist[i][j] + 1;
					q.push(make_pair(next_i, next_j));
					seen[next_i][next_j] = true;
				}
			}
		}

		return dist;
	}
	// 解法二 动态规划
	vector<vector<int>> updateMatrix2(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<int>> dp(m + 2, vector<int>(n + 2, INT_MAX / 2));
		// 左上
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				dp[i][j] = matrix[i - 1][j - 1] == 0 ? 0 : min(dp[i - 1][j], dp[i][j - 1]) + 1;

		// 右下
		for (int i = m; i >= 1; i--) 
			for (int j = n; j >= 1; j--) 
				dp[i][j] = matrix[i - 1][j - 1] == 0 ? 0 : min(dp[i][j], min(dp[i + 1][j], dp[i][j + 1]) + 1);

		for (int i = 1; i <= m; i++) 
			for (int j = 1; j <= n; j++) 
				matrix[i - 1][j - 1] = dp[i][j];

		return matrix;
	}
};

int main() {
	Solution sln;
	vector<vector<int>> matrix = { {0, 0, 0}, {0, 1, 0}, {1, 1, 1} };
	vector<vector<int>> result = sln.updateMatrix(matrix);
	for (auto& row : result) {
		for (auto& col : row) {
			cout << col << " ";
		}
		cout << endl;
	}
	return 0;
}