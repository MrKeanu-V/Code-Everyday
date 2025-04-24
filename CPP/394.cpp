/*
394. Decode String [Medium - 6]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
	// 解法一 栈+模拟 Time:O(n), Space:O(n)
	string decodeString_1(string s) {
		string res;
		stack<int> bits;
		stack<string> strs;
		int num = 0;
		for (char c : s) {
			if (isdigit(c)) num = num * 10 + c - '0';
			else if (isalpha(c)) res += c;	// include <ctype.h>
			else if (c == '[') {
				bits.push(num);
				num = 0;
				strs.push(res);
				res = "";
			}
			else {
				int times = bits.top();
				bits.pop();
				while (times--) res += strs.top();
				strs.pop();
			}
		}
		return res;
	}
};