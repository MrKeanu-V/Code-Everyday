/*
114. Flatten Binary Tree to Linked List	[Medium - 3]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
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
};