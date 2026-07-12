/*
516. Longest Palindromic Subsequence [Medium - 5]
*/
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <functional>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
	// �ⷨһ DP
	int longestPalindromicSubseq(string s) {
		int n = s.length();
		vector<vector<int>> dp(n, vector<int>(n, 0));

		for (int i = n - 1; i >= 0; i--) {
			dp[i][i] = 1;
			for (int j = i + 1; j < n; j++) {
				if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
				else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}

		return dp[0][n - 1];
	}
};

int main() {
	Solution sln;
	string s = "bbbab";
	cout << sln.longestPalindromicSubseq(s) << endl;
	s = "cbbd";
	cout << sln.longestPalindromicSubseq(s) << endl;
	return 0;
}