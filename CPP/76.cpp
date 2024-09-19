/*
76. Minimum Window Substring hard 最小覆盖子串 困难
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
	bool isContain(vector<int>& tcount, vector<int>& need) {
		for (int i = 0; i < 128; i++)
			if (tcount[i] > need[i])
				return false;
		
		return true;
	}

	// 解法一：滑动窗口
	string minWindow(string s, string t) {
		if (s.empty() || s.size() < t.size()) return "";
		int left = 0, right = 0, minLen = s.size() + 1, minLeft = 0;
		vector<int> tcount(128, 0), need(128, 0);
		for (auto& c : t)
			tcount[c]++;
		
		while (right < s.size()) {
			need[s[right]]++;
			while (isContain(tcount, need)) {
				if (right - left + 1 < minLen) {
					minLeft = left;
					minLen = right - left + 1;
				}
				need[s[left]]--;
				left++;
			}
			right++;
		}

		return minLen == s.size() +1?"":s.substr(minLeft, minLen);
	}
};

int main() {
	Solution sln;
	string s = "ADOBECODEBANC", t = "ABC";
	cout << sln.minWindow(s, t) << endl;
	return 0;
}
