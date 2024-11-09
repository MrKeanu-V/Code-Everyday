/*
01.04. Palindrom Permutation LCCI [Easy]
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <unordered_set>
using namespace std;

class Solution {
public:
	// �ⷨһ������
	bool canPermutePalindrome(string s) {
		unordered_set<char> count;
		for (int i = 0; i < s.size(); i++)
			if (count.find(s[i]) != count.end()) count.erase(s[i]);
			else count.insert(s[i]);
		return count.size() <= 1;
	}
	// �ⷨ����λ����״̬ѹ��
};

int main() {
	Solution sln;
	string s = "taccoa";
	cout << sln.canPermutePalindrome(s) << endl;
	return 0;
}