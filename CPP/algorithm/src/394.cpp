/*
394. Decode String [Medium - 6]
*/
#include "fnt/fnt_solution.h"
#include "fnt/fnt_utils.h"
using namespace fnt;

class Solution394 : public BaseSolution {
public:
	FNT_SOLUTION_KEY("394")
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

	void test() override {
		string s = "3[a]2[bc]";
		cout << decodeString_1(s) << endl;    // aaabcbc
		s = "3[a2[c]]";
		cout << decodeString_1(s) << endl;    // accaccacc
		s = "2[abc]3[cd]ef";
		cout << decodeString_1(s) << endl;    // abcabccdcdcdef
	}
};

FNT_REGISTER(Solution394);