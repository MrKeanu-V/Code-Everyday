/*
90. Subsets II [Medium - 5]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
    // �ⷨһ ���� ѡ��ѡ Time:O(2^n) Space:O(n)
    void backtrack_1(vector<vector<int>>& res, vector<int>& nums, vector<int>& path, int start) {
        if (start == nums.size()) return res.push_back(path);
        // ѡ
        path.push_back(nums[start]);
        backtrack_1(res, nums, path, start + 1);
        path.pop_back();
        // ��ѡ
        while (start < nums.size() - 1 && nums[start] == nums[start + 1]) start++;
        backtrack_1(res, nums, path, start + 1);
    }
    // �ⷨ�� ���� ö��ѡ�� Time:O(2^n) Space:O(n)
    void backtrack(vector<vector<int>>& res, vector<int>& nums, vector<int>& path, int start) {
        return res.push_back(path);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            // ѡ
            path.push_back(nums[i]);
            backtrack(res, nums, path, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> path;
        backtrack(res, nums, path, 0);
        return res;
    }
};