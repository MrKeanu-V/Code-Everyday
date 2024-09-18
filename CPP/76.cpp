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
	// 解法一：滑动窗口
	string minWindow(string s, string t) {
		if(s.size() < t.size()) return "";	// 细节
		unordered_map<char, pair<int, int>> smap, tmap;	// 统计t的字符出现个数和索引
		for (int i = 0; i < t.size(); i++) {
			smap[s[i]].first++;
			tmap[t[i]].first++;
		}
		vector<char> window;
		int left = 0, right = t.size() - 1, minLen = t.size();
	}
};

int main() {
	Solution s;
	string s = "ADOBECODEBANC", t = "ABC";
	cout << s.minWindow(s, t) << endl;
	return 0;
}
