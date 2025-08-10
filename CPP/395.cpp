/*
395. Longest Substring with At Least K Repeating Characters [Medium - 6]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
	// 解法一 分治+递归 Time:O(nlogn) Space:O(1)
	int longestSubstring(string s, int k) {
		int res = 0, left = 0, n = s.size();
		vector<int> split;
		unordered_map<char, int> cnt;
		for (char c : s) cnt[c]++;
		for (int i = 0; i < n; i++) if (cnt[s[i]] < k) split.push_back(i);
		if (split.empty()) return n;
		for (int i = 0; i < split.size(); i++) {
			int len = split[i] - left;
			if (len > res) res = max(res, longestSubstring(s.substr(left, len), k));
			left = split[i] + 1;
		}
		return res;
	}
};