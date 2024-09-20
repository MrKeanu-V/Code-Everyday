/*
2342. Maximum Subsequence Score medium
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int getSum(int n) {
        int res = -1;
        while (n>=1) {
            res += n % 10;
            n /= 10;
        }
            
        return res;
    }

    // 解法一：哈希表
    int maximumSum(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> dic;

        for (int i = 0; i < nums.size(); i++) {
            int sum = getSum(nums[i]);
            auto it = dic.find(sum);
            if (it != dic.end()) {
                res = max(res, it->second + nums[i]);
            }
            if (it == dic.end() || it->second < nums[i])
                dic[sum] = nums[i];
        }

        return res;
    }
};

int main() {
    Solution sln;
    vector<int> nums = { 18,43,36,13,7 };
    cout << sln.maximumSum(nums) << endl;
    return 0;
}