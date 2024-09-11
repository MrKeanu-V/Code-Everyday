/*
LeetCode 128. 最长连续序列
*/
#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    // 解法一：哈希表
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (int num : nums) {
            num_set.insert(num);
        }
        int res = 0;
        for (int num : num_set) {
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;
                while (num_set.count(currentNum + 1)) {
                    currentNum ++;
                    currentStreak ++;
                }
                res = max(res, currentStreak);
            }
        }
        return res;
    }
    // 解法二：排序+指针
    /*int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int res = 1, count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) continue;
            if (nums[i] != nums[i - 1] + 1) {
                count = 1;
            }
            else {
                count++;
                res = max(res, count);
            }
        }
        return res;
    }*/
};

int main() {
    Solution s;
    vector<int> nums = { 1,2,0,1 };
    cout << s.longestConsecutive(nums) << endl;
    return 0;
}