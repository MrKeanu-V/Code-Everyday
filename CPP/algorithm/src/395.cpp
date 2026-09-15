/*
395. Longest Substring with At Least K Repeating Characters [Medium - 6]
*/
#include "fnt/fnt_solution.h"
#include "fnt/fnt_utils.h"
using namespace fnt;

class Solution395 : public BaseSolution {
public:
	FNT_SOLUTION_KEY("395")
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

	void test() override {
		string s = "aaabb";
		int k = 3;
		cout << longestSubstring(s, k) << endl;    // 3
		s = "ababbc";
		k = 2;
		cout << longestSubstring(s, k) << endl;    // 5
	}
};

FNT_REGISTER(Solution395);