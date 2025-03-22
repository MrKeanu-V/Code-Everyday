/*
39. Combination Sum [Medium - 4]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
    // 解法一 回溯 枚举选哪个 Time:O(2^n) Space:O(n)
    vector<vector<int>> combinationSum_1(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        auto dfs = [&](auto dfs, int pre, int sum)->void {
            if (sum == target) return res.push_back(path);
            if (sum > target) return;
            for (int i = pre; i < n; ++i) {
                path.push_back(candidates[i]);
                dfs(dfs, i, sum + candidates[i]);
                path.pop_back();
            }
        };
        dfs(dfs, INT_MAX, 0);
        return res;
    }
    // 解法二 回溯 枚举选哪个
    vector<vector<int>> combinationSum_2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        auto dfs = [&](auto dfs, int idx, int left)->void {
            if (left == 0) return res.push_back(path);
            if (left < 0) return;
            for (int i = idx; i < n; ++i) {
                path.push_back(candidates[i]);
                dfs(dfs, i, left - candidates[i]);
                path.pop_back();
            }
        };
        dfs(dfs, 0, target);
        return res;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        auto dfs = [&](auto dfs, int idx, int left)->void {
            if (left == 0) return res.push_back(path);
            if (idx >= n || left < candidates[idx]) return;
            path.push_back(candidates[idx]);
            dfs(dfs, idx, left - candidates[idx]);
            path.pop_back();
            dfs(dfs, idx + 1, left);
        };
        dfs(dfs, 0, target);
        return res;
    }
};