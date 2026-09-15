/*
13. Roman to Integer [Easy - 3]
*/
#include "fnt/fnt_solution.h"
#include "fnt/fnt_utils.h"
using namespace fnt;

class Solution13 : public BaseSolution{
private:
	unordered_map<char, int> _roman = { {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
public:
	FNT_SOLUTION_KEY("13")

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

	void test() override {
		string s = "III";
		cout << romanToInt(s) << endl;   // 3
		s = "IV";
		cout << romanToInt(s) << endl;   // 4
		s = "IX";
		cout << romanToInt(s) << endl;   // 9
		s = "LVIII";
		cout << romanToInt(s) << endl;   // 58
		s = "MCMXCIV";
		cout << romanToInt(s) << endl;   // 1994
	}
};

FNT_REGISTER(Solution13);