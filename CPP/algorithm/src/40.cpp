/*
40. Combination Sum II [Medium - 5]
*/
#include "fnt/fnt_solution.h"
#include "fnt/fnt_utils.h"
using namespace fnt;

class Solution40 : public BaseSolution {
public:
    FNT_SOLUTION_KEY("40")

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

    void test() override {
        vector<int> candidates = { 10,1,2,7,6,1,5 };
        int target = 8;
        vector<vector<int>> res = combinationSum2(candidates, target);
        printVector2D(res);    // [[1,1,6],[1,2,5],[1,7],[2,6]]
    }
};

FNT_REGISTER(Solution40)