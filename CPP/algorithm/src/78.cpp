/*
78. Subsets [Medium - 4]
*/
#include "fnt/fnt_solution.h"
#include "fnt/fnt_utils.h"
using namespace fnt;

class Solution78 : public BaseSolution {
public:
    FNT_SOLUTION_KEY("78")

    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) return {};
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> path;
        auto dfs = [&](auto&& dfs, int idx) -> void {
            if (idx == n) return res.push_back(path);
            dfs(dfs, idx + 1);
            path.push_back(nums[idx]);
            dfs(dfs, idx + 1);
            path.pop_back();
        };
        dfs(dfs, 0);
        return res;
    }

    void test() override {
        vector<int> nums = { 1, 2, 3 };
        vector<vector<int>> res = subsets(nums);
        printVector2D(res);    // [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
    }
};

FNT_REGISTER(Solution78);