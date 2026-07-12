/*
40. Combination Sum II [Medium - 5]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //ranges::sort(candidates);
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        int n = candidates.size();
        auto dfs = [&](auto&& dfs, int idx, int tar)->void {   // this auto&& dfs is a recursive lambda, it is a C++17 feature
            if (tar == 0) return res.push_back(path);
            if (idx >= n || tar < 0) return;
            path.push_back(candidates[idx]);
            dfs(dfs, idx + 1, tar - candidates[idx]);
            path.pop_back();
            while (++idx < n && candidates[idx] == candidates[idx - 1]);
            dfs(dfs, idx, tar);
        };
        dfs(dfs, 0, target);
        return res;
    }
};