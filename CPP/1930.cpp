/*
1930. 长度为3的不同回文子序列 中等
*/
#define __builtin_popcount __popcnt
#define __builtin_popcountlll __popcnt
#include <iostream>
#include <vector>
#include <algorithm>
//#include <ranges>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <bit>	//__builtin_popcount
using namespace std;

class Solution {
public:
	// 解法一：暴力 TLE
	int countPalindromicSubsequence1(string s) {
		int res = 0, n = s.length();
		vector<vector<int>> used(26, vector<int>(26, 0));	// row:字符 col:是否用过
		
		for (int i = 1; i < n - 1; i++) {
			string right = s.substr(i+1, n - i);
			for (int j = 0; j < i; j++) {
				if (used[s[i]-'a'][s[j] - 'a'] == 0) {
					if (right.find(s[j]) != string::npos) {
						res++;
						used[s[i] - 'a'][s[j] - 'a'] = 1;
					}
				}
			}
		}

		return res;
	}
 	// 解法二：优化
	int countPalindromicSubsequence(string s) {
		int res = 0, n = s.length();
		vector<int> pre(26, 0), suf(26, 0), has(26, 0);
		for (int i = 1; i < s.size(); ++i)
			suf[s[i] - 'a']++;
		for (int i = 1; i < n - 1; i++) {
			pre[s[i - 1] - 'a']++;
			suf[s[i] - 'a']--;
			for (int j = 0; j < 26; j++) {
				if (pre[j] && suf[j])
					has[s[i] - 'a'] |= (1 << j);
			}
		}
		for(int i:has)
			res+= __builtin_popcount(i);
		return res;
	}
};

int main() {
	Solution sln;
	string s = "ckafnafqo";
	cout<<sln.countPalindromicSubsequence(s)<<endl;
	return 0;
}