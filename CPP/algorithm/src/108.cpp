/*
108. Convert Sorted Array to Binary Search Tree [Esay - 4]
*/
#include "fnt/fnt_solution.h"
#include "fnt/fnt_utils.h"
using namespace fnt;

class Solution108 : public BaseSolution {
public:
    FNT_SOLUTION_KEY("108")

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

    void test() override {
        vector<int> nums = { -10, -3, 0, 5, 9 };
        TreeNode* root = sortedArrayToBST(nums);
        printTree(root);
    }
};

FNT_REGISTER(Solution108);
