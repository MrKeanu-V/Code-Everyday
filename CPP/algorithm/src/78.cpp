/*
78. Subsets [Medium - 4]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
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
};