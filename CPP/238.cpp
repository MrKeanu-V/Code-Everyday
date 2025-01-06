/*
238. Product of Array Except Self [Medium - 5]
*/
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <functional>
#include <ranges>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    //解法一 除法模拟
    vector<int> productExceptSelf_1(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        long long product = 1;
        int zero_count = 0;
        for (int num : nums) {
            if (num != 0) product *= num;
            else zero_count++;
        }
        if (zero_count > 1) return res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                res[i] = product;
            else res[i] = zero_count == 1 ? 0 : product / nums[i];
        }
        return res;
    }
    // 解法二 前后缀分解
    vector<int> productExceptSelf_2(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0), prefix(n, 1), suffix(n, 1);

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
            suffix[n - i - 1] = suffix[n - i] * nums[n - i];
        }

        for (int i = 0; i < n; i++) {
            res[i] = prefix[i] * suffix[i];
        }
        
        return res;
    }
    // 解法二优化
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), suffix = 1;
        vector<int> res(n, 1);

        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            suffix *= nums[i + 1];
            res[i] *= suffix;
        }

        return res;
    }
};

//int main() {
//    Solution sln;
//    vector<int> nums = { 1, 2, 3, 4, 0, 6, 7, 8, 9 };
//    vector<int> ans = sln.productExceptSelf(nums);
//    for (auto& num : ans)
//        cout << num << " ";
//    cout << endl;
//    return 0;
//}