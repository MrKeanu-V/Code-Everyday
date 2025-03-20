/*
47. Permutations II [Medium - 5]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
    // 解法一 回溯 枚举选什么 Time:O(N!) Space:O(N)
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        vector<int> path, visited(n, false);
        sort(nums.begin(), nums.end());
        function<void(int)> dfs = [&](int depth)->void {
            if (depth == n) return res.push_back(path);
            for (int i = 0; i < n; i++) {
                if (visited[i] || i > 0 && !visited[i - 1] && nums[i] == nums[i - 1]) continue;
                visited[i] = true;
                path.push_back(nums[i]);
                dfs(depth + 1);
                path.pop_back();
                visited[i] = false;
            }
        };
        dfs(0);
        return res;
    }
};