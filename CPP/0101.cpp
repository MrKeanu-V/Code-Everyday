/*
01.01. Is Unique LCCI [Esay]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>
#include <functional>
using namespace std;

class Solution {
public:
	bool isUnique1(string astr) {
		if (astr.empty()) return true;
		sort(astr.begin(), astr.end());
		for (int i = 0; i < astr.size() - 1; i++) 
			if (astr[i] == astr[i + 1]) return false;
		return true;
	}
	// ½â·¨¶þ ×´Ì¬Ñ¹Ëõ
	bool isUnique(string astr) {
		int mask = 0;
		for (int i = 0; i < astr.size(); i++) {
			if (mask & (1 << (astr[i] - 'a'))) return false;
			mask |= (1 << (astr[i] - 'a'));
		}
		return true;
	}
};

int main() {
	Solution sln;
	string astr = "ltcode";
	cout << sln.isUnique(astr) << endl;
	return 0;
}