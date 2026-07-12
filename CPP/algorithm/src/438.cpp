/*
438. Find All Anagrams in a String medium 找到字符串中所有字母异位词 中等
*/
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

class Solution {
public:
	// 解法一：暴力法 TLE
	vector<int> findAnagrams1(string s, string p) {
		if (s.size() < p.size())
			return vector<int>();
		vector<int> res;
		unordered_map<char, int> pmap;
		for (auto& c : p)
			pmap[c]++;
		
		for (int i = 0; i < s.size() - p.size() + 1; i++) {
			unordered_map<char, int> smap;
			for (int j = i; j < i + p.size(); j++)
				smap[s[j]]++;
			if (pmap == smap)
				res.push_back(i);
		}

		return res;
	}

	// 解法二：滑动窗口
	vector<int> findAnagrams2(string s, string p) {
		vector<int> res;
		if (s.size() < p.size()) {	// 窗口大小小于p，不可能有结果
			return res;
		}
		vector<int> smap(26, 0), pmap(26, 0);
		for (int i = 0; i < p.size(); i++) {
			smap[s[i] - 'a']++;
			pmap[p[i] - 'a']++;
		}
		if (smap == pmap)
			res.push_back(0);
		for (int i = 1; i <= s.size() - p.size(); i++) {
			smap[s[i - 1] - 'a']--;
			smap[s[i+p.size() - 1] - 'a']++;
			if (smap == pmap) {
				res.push_back(i);
			}
		}
		
		return res;
	}

	// 解法三：哈希+滑动窗口（解法一优化）
	vector<int> findAnagrams(string s, string p) {
		if (s.size() < p.size())	// 细节
			return vector<int>();
		vector<int> res;
		unordered_map<char, int> pmap, smap;
		for (int i = 0; i < p.size(); i++) {
			smap[s[i]]++;
			pmap[p[i]]++;
		}
		if (smap == pmap)
			res.push_back(0);

		for (int i = 1; i <= s.size() - p.size(); i++) {
			if (--smap[s[i - 1]] == 0) {
				smap.erase(s[i - 1]);
			}
			smap[s[i + p.size() - 1]]++;
			
			if (pmap == smap)
				res.push_back(i);
		}

		return res;
	}
};

int main() {
	Solution sln;
	//string s = "ababababab", p = "aab";
    string s = "cbaebabacd", p = "abc";
	vector<int> res = sln.findAnagrams(s, p);
	for (auto& i : res)
		cout << i << " ";
	return 0;
}
