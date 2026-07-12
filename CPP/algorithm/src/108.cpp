/*
108. Convert Sorted Array to Binary Search Tree [Esay - 4]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
private:
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left == right) return nullptr;
        int mid = left + ((right - left) >> 1); // mid = left + (right - left) / 2;    // avoid overflow mid = left + ((right - left) >> 1);
        return new TreeNode(nums[mid], helper(nums, left, mid), helper(nums, mid + 1, right));
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        return helper(nums, 0, nums.size());    // [0, nums.size())
    }
};
