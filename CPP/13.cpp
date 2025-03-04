/*
13. Roman to Integer [Easy - 3]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
private:
	unordered_map<char, int> _roman = { {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
public:
	int romanToInt_1(string s) {
		int sum = 0;
		for (int i = 1; i < s.length();i++) {
			int pre = _roman[s[i - 1]], cur = _roman[s[i]];
			sum += pre < cur ? -pre : pre;
		}
		return sum + _roman[s.back()];
	}
	int romanToInt(string s) {
		int res = 0;
		for (int i = s.length() - 2; i >= 0; i--) {
			int cur = _roman[s[i]], next = _roman[s[i + 1]];
			res += cur < next ? -cur : cur;
		}
		return res;
	}
};