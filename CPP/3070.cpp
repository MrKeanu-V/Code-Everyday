/*
3070. Ԫ�غ�С�ڵ���k���Ӿ�����Ŀ medium
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
using namespace std;

class Solution {
public:
	// �ⷨһ����άǰ׺�� modal
	int countSubmatrices(vector<vector<int>>& grid, int k) {
		int ans = 0, m = grid.size(), n = grid[0].size();
		vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));	// �࿪һ��һ�У��������

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + grid[i-1][j-1];
				if (sum[i][j] <= k)
					ans++;
			}
		}

		return ans;
	}
};

int main() {
	Solution sln;
	vector<vector<int>> grid = { {7,6,3}, {6,6,1} };
	int k = 18;
	cout << sln.countSubmatrices(grid, k) << endl;
	return 0;
}
