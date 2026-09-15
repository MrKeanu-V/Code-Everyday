/*
LC Realize strStr() [Esay]
*/
#include "fnt/fnt_solution.h"
#include "fnt/fnt_utils.h"
using namespace fnt;

class Solution_LCP01 : public BaseSolution {
public:
    FNT_SOLUTION_KEY("LCP01")

	// 解法一 暴力法 Time:O(n*m) Space:O(1)
	int strStr_1(string haystack, string needle) {
		int len1 = haystack.size(), len2 = needle.size();
		for (int i = 0; i < len1; i++) {
			if (len1 - i < len2) return -1;
			if (haystack[i] == needle[0]) {
				bool isMatch = true;
				for (int j = 0; j < len2; j++) {
					if (haystack[i + j] != needle[j]) {
						isMatch = false;
						break;
					}
				}
				if (isMatch) return i;
			}
		}
		return -1;
	}
	// 解法二 KMP算法 Time:O(n+m) Space:O(m)
	int strStr(string haystack, string needle) {
        return haystack.find(needle);
	}

	void test() override {
		string haystack = "leetcode";
		string needle = "leeto";
		cout << strStr(haystack, needle) << endl;
		haystack = "sadbutsad";
		needle = "sad";
		cout << strStr(haystack, needle) << endl;
	}
};

FNT_REGISTER(Solution_LCP01);
//int main() {
//	Solution().test();
//	return 0;
//}