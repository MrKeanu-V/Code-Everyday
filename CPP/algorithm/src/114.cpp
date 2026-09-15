/*
114. Flatten Binary Tree to Linked List	[Medium - 3]
*/
#include "fnt/fnt_solution.h"
#include "fnt/fnt_utils.h"
using namespace fnt;

class Solution114 : public BaseSolution {
public:
    FNT_SOLUTION_KEY("114")

    // 解法一 递归 Time:O(n) Space:O(n)
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        flatten(left);
        flatten(right);
        root->left = nullptr;
        root->right = left;
        TreeNode* cur = root;
        while (cur->right) cur = cur->right;
        cur->right = right;
    }

    void test() override {
        vector<int> nums = { 1,2,5,3,4,NULL,6 };
        TreeNode* root = createTree(nums);
        printTree(root);
        flatten(root);
        printTree(root);
    }
};

FNT_REGISTER(Solution114);