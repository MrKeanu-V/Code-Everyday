/*
784. Letter Case Permutation [Medium - 1342 - Permutation]
*/
#include "fnt/fnt_solution.h"
#include "fnt/fnt_utils.h"
using namespace fnt;

class Solution784 : public BaseSolution {
private:
    unordered_map<char, vector<char>> m;
public:
    FNT_SOLUTION_KEY("784")

    Solution784() {
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

    void test() override {
        string s = "a1b2";
        vector<string> res = letterCasePermutation_1(s);
        printVector1D(res);    // ["a1b2","a1B2","A1b2","A1B2"]
        s = "3z4";
        res = letterCasePermutation_2(s);
        printVector1D(res);    // ["3z4","3Z4"]
    }
};

FNT_REGISTER(Solution784);