/*
76. Minimum Window Substring hard ��С�����Ӵ� ����
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
	// �ⷨһ����������
	string minWindow(string s, string t) {
		if(s.size() < t.size()) return "";	// ϸ��
		unordered_map<char, pair<int, int>> smap, tmap;	// ͳ��t���ַ����ָ���������
		for (int i = 0; i < t.size(); i++) {
			smap[s[i]].first++;
			tmap[t[i]].first++;
		}
		vector<char> window;
		int left = 0, right = t.size() - 1, minLen = t.size();
	}
};

int main() {
	Solution s;
	string s = "ADOBECODEBANC", t = "ABC";
	cout << s.minWindow(s, t) << endl;
	return 0;
}
