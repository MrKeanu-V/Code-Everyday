/*
494. Target Sum. [Medium - 5 - DP|Backtrack]
*/
#include "fnt_template.h"
#include "fnt_solution.h"

class Solution494 {
public:
    // Method 2: DP Time: O(n) Space: O(n)
    /*
    * In fact, this problem can be transformed to a backpack problem.
    * You can consider it as you need two backpacks, one with positive sign and the other with negative sign
    * and the sum of the two backpacks` values is equal to target.
    * Suppose pack1 is the backpack with positive sign and pack2 is the backpack with negative sign.
    * So the problem can be described as:
    * pack1 - pack2 = target
    * pack1 + pack2 = sum(nums)
    * => pack1 = (target + sum(nums)) / 2
    * => pack1 is the target value of the backpack problem.
    * So, this problem now becomes to find the number of ways to fill the pack1 with nums.
    */
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum || (sum + target) % 2 == 1) return 0;
        int capacity = (sum + target) / 2;
        vector<int> dp(capacity + 1, 0);
        dp[0] = 1;
        for (int num : nums)
            for (int i = capacity; i >= num; i--)
                dp[i] += dp[i - num];
        return dp[capacity];
    }
    // Method 1: Backtrack Time: O(2^n) Space: O(n)
    int findTargetSumWays_1(vector<int>& nums, int target) {
        int res = 0;
        dfs(nums, target, 0, 0, res);
        return res;
    }

    void dfs(vector<int>& nums, int target, int sum, int depth, int& count) {
        if (depth == nums.size()) {
            if (sum == target) count++;
            return;
        }
        dfs(nums, target, sum + nums[depth], depth + 1, count);
        dfs(nums, target, sum - nums[depth], depth + 1, count);
    }

    void test() {
        vector<int> nums = {1, 1, 1, 1, 1};
        int target = 3;
        cout << findTargetSumWays(nums, target) << endl;
        nums = {1};
        target = 1;
        cout << findTargetSumWays(nums, target) << endl;
    }
};

FNT_REGISTER(494)