/**
@Author: MrKeanu
@Date: 2026-07-12
@Description: Leetcode 3. Longest Substring Without Repeating Characters [Medium]
@History: Original creation — brute force + sliding window solutions.
*/
#include "fnt/fnt_utils.h"
#include "fnt/fnt_solution.h"
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
using namespace fnt;

class Solution3 : public BaseSolution {
public:
    FNT_SOLUTION_KEY("3")

	// 解法一：滑动窗口
	int lengthOfLongestSubstring(string s) {
		int maxLen = 0;
		vector<char> v;
		for (auto& c : s) {
			auto it = find(v.begin(), v.end(), c);
			if (it == v.end()) {
				v.push_back(c);
			}
			else {
				maxLen = max(maxLen, int(v.size()));
				v.erase(v.begin(), it + 1);
				v.push_back(c);
			}
		}
		return max(maxLen, int(v.size()));	// 边界条件
	}

	// 解法二 哈希+滑动窗口
	int lengthOfLongestSubstring_2(string s) {
		int maxLen = 0, l = 0, r = 0;
		unordered_set<char> hash;
		while (r < s.length()) {
			while (hash.count(s[r])) hash.erase(s[l++]);
			hash.insert(s[r++]);
			maxLen = max(maxLen, r - l);
		}
		return maxLen;
	}

    void test() override {
        string str = "aab";
        cout << lengthOfLongestSubstring(str) << endl;       // 2
        str = "abcabcbb";
        cout << lengthOfLongestSubstring(str) << endl;       // 3
        str = "pwwkew";
        cout << lengthOfLongestSubstring_2(str) << endl;     // 3
    }
};

FNT_REGISTER(Solution3);