/*
98. Validate Binary Search Tree [Medium - 3]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
private:
    long long pre = LLONG_MIN;
public:
    // 解法一 前序 递归 Time:O(n) Space:O(1)
    bool isValidBST_1(TreeNode* root, long long min = LLONG_MIN, long long max = LLONG_MAX) {
        if (!root) return true;
        long long val = root->val;
        return val>min&&val<max&&isValidBST_1(root->left, min, val)&&isValidBST_1(root->right, val, max);
    }
    // 中序 变体
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if (!isValidBST(root->left) || pre >= root->val) return false;
        pre = root->val;
        return isValidBST(root->right);
    }

    void test() {
        vector<int> nums = { 2, 1, 3 };
        TreeNode* root = createTree(nums);
        printTree(root);
        string res = isValidBST(root) ? "true" : "false";
        cout << res << endl;
        
        nums = { 2147483647 };
        root = createTree(nums);
        printTree(root);
        res = isValidBST(root) ? "true" : "false";
        cout << res << endl;

        nums = { 5, 4, 6, NULL, NULL, 3, 7 };
        root = createTree(nums);
        printTree(root);
        res = isValidBST(root) ? "true" : "false";
        cout << res << endl;
    }
};

//int main() {
//    Solution().test();
//    vector<int> nums;
//    return 0;
//}