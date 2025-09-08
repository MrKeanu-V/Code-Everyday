/*
230. Kth Smallest Element in a BST [Medium - 3]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
private:
    void inorder(TreeNode* node, vector<int>& list) {
        if (node == nullptr) return;
        list.emplace_back(node->val);
        inorder(node->left, list);
        inorder(node->right, list);
    }
public:
    // Solution 1: Inorder Traversal + Sort Time: O(nlogn) Space: O(n)
    int kthSmallest(TreeNode* root, int k) {
        vector<int> list;
        inorder(root, list);
        sort(list.begin(), list.end());
        return list[k - 1];
    }
    void test() {
        vector<int> nums = { 3,1,4,NULL,2};
        TreeNode* root = createTree(nums);
        cout << kthSmallest(root, 1) << endl;
    }
};

//int main() {
//    Solution().test();
//    return 0;
//}