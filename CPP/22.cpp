/*
22. Generate Parentheses [Medium - 5]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
    // 解法一 回溯 Time:O(4^n / sqrt(n)) Space:O(n)
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;
        function<void(int, int)> dfs = [&](int left, int right) {
            if (right == 0) return res.push_back(path);
            if (left) {
                path.push_back('(');
                dfs(left - 1, right);
                path.pop_back();
            }
            if (right>left) {
                path.push_back(')');
                dfs(left, right - 1);
                path.pop_back();
            }
        };
        dfs(n, n);
        return res;
    }
};