/*
187. Repeated DNA Sequences [Medium - 4]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
private:
    unordered_map<char, int> bin = { {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3} };
public:
    // 解法一 哈希+滑动窗口
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string, int> cnt;
        for (int i = 0; i + 10 <= s.size(); i++) {
            string sub = s.substr(i, 10);
            if(++cnt[sub]==2) res.push_back(sub);
        }
        return res;
    }
    // 解法二 位运算+哈希+滑动窗口
    vector<string> findRepeatedDnaSequences_2(string s) {
        vector<string> res;
        int n = s.length(), bit = 0;
        if (n < 10) return res;
        for (int i = 0; i < 9; i++) bit = (bit << 2) | bin[s[i]];
        unordered_map<int, int> cnt;
        for (int i = 0; i < n - 9; i++) {
            bit = ((bit << 2) | bin[s[i + 9]]) & ((1 << 20) - 1);
            if(++cnt[bit]==2) res.push_back(s.substr(i, 10));
        }
        return res;
    }
};