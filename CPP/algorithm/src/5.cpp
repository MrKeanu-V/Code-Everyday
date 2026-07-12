/**
@Author: MrKeanu
@Date: 2026-07-12
@Description: Leetcode 5. Longest Palindromic Substring [Medium]
@History: Original creation — brute force + Manacher algorithm solutions.
*/
#include "fnt_utils.h"
#include "fnt_solution.h"
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;
using namespace fnt;

class Solution5 : public BaseSolution {
public:
    FNT_SOLUTION_KEY("5")

	// 解法一 暴力法
	string longestPalindrome1(string s) {
		int n = s.size(), l = 0, r = 0;
		if (n < 2) return s;
		function<bool(int, int)> isPalindrome = [&](int left, int right)->bool {
			while (left < right) {
				if (s[left] != s[right]) return false;
				left++;
				right--;
			}
			return true;
		};
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				if (isPalindrome(i, j) && j - i > r - l) {
					l = i;
					r = j;
				}
			}
		}
		return s.substr(l, r - l + 1);
	}

	// 解法二 Manacher算法
	string longestPalindrome(string s) {
		if (s.size() < 2) return s;

		// 预处理字符串
		string tmp = "$#";
		for (char c : s) {
			tmp += c;
			tmp += '#';
		}
		tmp += '!';
		
		// Manacher
		int n = tmp.size(), right = 0, center = 0, start = 0, maxLen = 0;
		vector<int> p(n, 0);
		auto manacher = [&](int left, int right)->int {
			while (left >= 0 && right < n && tmp[left] == tmp[right]) {
				left--;
				right++;
			}
			return (right - left) / 2 - 1;
		};
		for (int i = 0; i < n; i++) {
			if (right < i) p[i] = manacher(i, i);
			else {
				int minArm = min(right - i, p[2 * center - i]);
				p[i] = manacher(i - minArm, i + minArm);
			}
			if (i + p[i] > right) {
				right = i + p[i];
				center = i;
			}
			if (p[i] > maxLen) {
				maxLen = p[i];
				start = (i - maxLen) / 2;
			}
		}
		return s.substr(start, maxLen);
	}

    void test() override {
        string s = "babad";
        cout << longestPalindrome(s) << endl;    // "bab" or "aba"
        s = "cbbd";
        cout << longestPalindrome(s) << endl;    // "bb"
    }
};

FNT_REGISTER(Solution5);