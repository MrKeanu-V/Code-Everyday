/*
139. Word Break [Medium - 5]
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
#include <numeric>
#include <ranges>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
	// 解法一 DP 转化背包问题 搜索和DP本质上相同
	bool wordBreak1(string s, vector<string>& wordDict) {
		auto wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
		
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (int i = 1; i <= s.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (dp[j] && wordSet.count(s.substr(j, i - j))) {
					dp[i] = true;
					break;
				}
			}
		}
		return dp[s.size()];
	}
	// 解法二 DFS + 记忆化搜索
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> words(wordDict.begin(), wordDict.end());
		int n = s.size(), max_len = 0;
		for (string word : wordDict) max_len = max(max_len, (int)word.length());
		vector<int> memo(n + 1, -1);
		auto dfs = [&](auto& dfs, int start)->bool {
			if (start == 0) return true;
			int& res = memo[start];
			if (res != -1) return res;
			for (int j = start - 1; j >= max(0, start - max_len); j--) {
				if (words.count(s.substr(j, start - j)) && dfs(dfs, j)) return res = true;
			}
			return res = false;
		};
		return dfs(dfs, n);
	}
};

void printResult(bool res) {
	cout << (res ? "true" : "false") << endl;
}

int main() {
	Solution sln;
	string s = "leetcode";
	vector<string> wordDict = { "leet", "code" };
	printResult(sln.wordBreak(s, wordDict));
	s = "applepenapple";
	wordDict = { "apple", "pen" };
	printResult(sln.wordBreak(s, wordDict));
	s = "catsandog";
	wordDict = { "cats", "dog", "sand", "and", "cat" };
	printResult(sln.wordBreak(s, wordDict));
	s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	wordDict = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
	printResult(sln.wordBreak(s, wordDict));
	return 0;
}