/*
Leetcode 3. Longest Substring Without Repeating Characters medium 无重复字符的最长子串 中等
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <functional>
using namespace std;

class Solution {
public:
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
};

int main() {
	Solution s;
	string str = "aab";
	cout << s.lengthOfLongestSubstring(str) << endl;
	return 0;
}
