/*
14. Longest Common Prefix [Easy - 2]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
    // �ⷨһ ����ɨ�� Time: O(n*m) Space: O(1)
    string longestCommonPrefix_1(vector<string>& strs) {
        string res = strs[0];
        for (int i = 1; i < strs.size();i++) {
            string com = longestCommonPrefix(res, strs[i]);
            if (com.empty()) return {};
        }
        return res;
    }
    // �ⷨ�� ����ɨ�� Time: O(n*m) Space: O(1)
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            string com = longestCommonPrefix(res, strs[i]);
            if (com.empty()) return {};
        }
        return res;
    }
    // �����ǰ׺ Time:O(n) Space:O(1)
    string longestCommonPrefix(const string& s1, const string& s2) {
        int len = min(s1.length(), s2.length()), i = 0;
        while (i < len && s1[i] == s2[i]) i++;
        return s1.substr(0, i);
    }
};