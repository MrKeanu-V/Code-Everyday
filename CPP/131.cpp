/*
131. Palindrome Partitioning [Medium - 5]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
private:
    vector<vector<int>> dp;
public:
    // 解法一 回溯+动规 Time: O(n*2^n) Space: O(n*2^n)
    vector<vector<string>> partition(string s) {
        int n = s.size();
        dp.resize(n, vector<int>(n, true));
        vector<vector<string>> res;
        vector<string> cur;
        function<void(int)> dfs = [&](int idx) {
            if (idx == n) return res.push_back(cur);
            for (int i = idx; i < n; i++) {
                if (dp[idx][i]) {
                    cur.push_back(s.substr(idx, i - idx + 1));
                    dfs(i + 1);
                    cur.pop_back();
                }
            }
        };
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
        }
        dfs(0);
        return res;
    }
};