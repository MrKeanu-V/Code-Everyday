/*
LC Is Palindrome [Esay]
*/

#include "pub_template.h"

class Solution {
private:
	unordered_map<char, char> map = {
		{'A','a'},{'B','b'},{'C','c'},{'D','d'},{'E','e'},{'F','f'},{'G','g'},{'H','h'},{'I','i'},{'J','j'}, {'K','k'},
				{'L','l'},{'M','m'},{'N','n'},{'O','o'},{'P','p'},{'Q','q'},{'R','r'},{'S','s'},{'T','t'},{'U','u'},{'V','v'},{'W','w'},
				{'X','x'},{'Y','y'},{'Z','z'}
	};
public:
	bool isPalindrome(string s) {
		int l, r, len = s.length();
		vector<char> str;
		if (len == 0) return true;
		for (int i = 0; i < len; i++) {
			if (s[i] >= 'A' && s[i] <= 'Z')
				str.push_back(s[i] + 32); // 不同编译器A和a的ASCII码不同
				//str.push_back(map[s[i]]);
			else if (s[i] >= 'a' && s[i] <= 'z')
				str.push_back(s[i]);
			else if (s[i] >= '0' && s[i] <= '9')
				str.push_back(s[i]);
		}
		l = 0, r = str.size() - 1;
		while (l < r) {
			if (str[l] != str[r]) return false;
			l++, r--;
		}
		return true;
	}

	void test() {
		string str = "A man, a plan, a canal: Panama";
		string str2 = "race a car";
		string str3 = "0P";
		string ans = isPalindrome(str) ? "true" : "false";
		cout << ans << endl;
		ans = isPalindrome(str2) ? "true" : "false";
		cout << ans << endl;
		ans = isPalindrome(str3) ? "true" : "false";
		cout << ans << endl;
	}
};

//int main() {
//	Solution().test();
//	return 0;
//}