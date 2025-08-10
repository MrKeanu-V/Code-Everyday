/*
77. Combinations [Medium - 4]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
    // 解法一 回溯 选或不选
    void backtrack_1(vector<vector<int>>& res, vector<int>& path, int start, int k, int n) {
        if (start > n) return;
        if (path.size() == k) return res.push_back(path);
        // 不选
        backtrack_1(res, path, start + 1, k, n);
        // 选
        path.push_back(start);
        backtrack_1(res, path, start + 1, k, n);
        path.pop_back();
    }
    // 解法二 回溯 每次选一个
    void backtrack(vector<vector<int>>& res, vector<int>& path, int start, int k, int n) {
        if (path.size() == k) return res.push_back(path);
        for (int i = start; i <= n; i++) {
            // 选
            path.push_back(i);
            backtrack(res, path, i + 1, k, n);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(res, path, 1, k, n);
        return res;
    }

    // 解法一 回溯 枚举选什么
    vector<vector<int>> combine_3(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        auto dfs = [&](auto&& dfs, int depth) {
            if (path.size() == k) return res.push_back(path);
            for (int i = depth; i <= n; i++) {
                path.push_back(i);
                dfs(dfs,i + 1);
                path.pop_back();
            }
        };
        dfs(dfs,1);
        return res;
    }
    vector<vector<int>> combine_4(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        auto dfs = [&](auto&& dfs, int depth) {
            if (path.size() == k) return res.push_back(path);
            if (depth > n) return;
            // 不选
            dfs(dfs, depth + 1);
            // 选
            path.push_back(depth);
            dfs(dfs, depth + 1);
            path.pop_back();
        };
        dfs(dfs, 1);
        return res;
    }
};