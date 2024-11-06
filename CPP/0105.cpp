/*
01.05. One Away Lcci [Medium]
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

class Solution {
public:
	// 问题进行抽象
	bool oneEidtAway(string first, string second) {
		int len1 = first.size(), len2 = second.size(), diff = abs(len1 - len2);
		if (diff > 1) return false;
		for (int i = 0; i < min(len1, len2); i++) {
			if (first[i] != second[i]) {
				if (diff == 1)
					return first.substr(i + 1) == second.substr(i) || first.substr(i) == second.substr(i + 1);
				else
					return first.substr(i + 1) == second.substr(i + 1);
			}
		}
		return true;
	}
};

int main() {
	Solution sln;
	string first = "a", second = "b";
	bool result = sln.oneEidtAway(first, second);
	if (result) cout << "true" << endl;
	else cout << "false" << endl;
	return 0;
}