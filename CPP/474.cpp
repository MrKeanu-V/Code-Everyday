/*
474. Ones and Zeroes [Medium - 6]
*/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges>
#include <numeric> // accumulate
#include <limits>
#include <functional>
using namespace std;

class Solution {
private:
	pair<int,int> getZeroAndOne(string str) {
		pair<int, int> res(0, 0);
		res.first = count_if(str.begin(), str.end(), [](char c) { return c == '0'; });
		res.second = str.size() - res.first;
		return res;
	}
public:
	// �ⷨһ 01�������� m*n�ռ临�Ӷ� ��m��n�ֱ�����ɱ���������ÿ���ַ����������Ʒ��0��1������Ϊ��Ʒ����
	int findMaxForm(vector<string>& strs, int m, int n) {
		// DP����
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		// value���� first:'0' second:'1'
		vector<pair<int,int>> values(strs.size() + 1);
		for(int i=0;i<strs.size();++i) values[i+1] = getZeroAndOne(strs[i]);
		// DP
		for (int i = 1; i < strs.size() + 1; ++i) 
			for (int j = m; j >= values[i].first; --j) 
				for (int k = n; k >= values[i].second; --k) 
					dp[j][k] = max(dp[j][k], dp[j - values[i].first][k - values[i].second] + 1);
		return dp[m][n];
	}
};

int main() {
	Solution sln;
	vector<string> nums = { "10", "0001", "111001", "1", "0" };
	int m = 5, n = 3;
	cout << sln.findMaxForm(nums, m, n) << endl;
	return 0;
}