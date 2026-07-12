/*
784. Letter Case Permutation [Medium - 1342 - Permutation]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
private:
    unordered_map<char, vector<char>> m;
public:
    Solution() {
        for (char c = 'a'; c <= 'z'; ++c) m[c].push_back(c), m[c].push_back(c - 'a' + 'A');
        for (char c = 'A'; c <= 'Z'; ++c) m[c].push_back(c), m[c].push_back(c - 'A' + 'a');
    }
    vector<string> letterCasePermutation_1(string s) {
        int n = s.length();
        vector<string> res;
        string path;
        function<void(int)> dfs = [&](int idx)->void {
            if (idx == n) return res.push_back(path);
            if (m.count(s[idx])) {
                for (auto c : m[s[idx]]) {
                    path += c, dfs(idx + 1);
                    path.pop_back();
                }
            }
            else path += s[idx], dfs(idx + 1), path.pop_back();
        };
        dfs(0);
        return res;
    }
    vector<string> letterCasePermutation_2(string s) {
        int n = s.length();
        vector<string> res;
        string path;
        function<void(int)> dfs = [&](int idx)->void {
            if (idx == n) return res.push_back(path);
            if (s[idx] >= 'a' && s[idx] <= 'z' || s[idx] >= 'A' && s[idx] <= 'Z') {
                path += tolower(s[idx]), dfs(idx + 1), path.pop_back();
                path += toupper(s[idx]), dfs(idx + 1), path.pop_back();
            }
            else path += s[idx], dfs(idx + 1), path.pop_back();
        };
        dfs(0);
        return res;
    }
};