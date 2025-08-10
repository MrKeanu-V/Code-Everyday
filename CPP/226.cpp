/*
226. Invert Binary Tree [Easy - 3]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
	// 解法一 递归 Time:O(n) Space:O(n)
	TreeNode* invertTree_1(TreeNode* root) {
		if (!root) return {};
		TreeNode* tmp = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(tmp);
		return root;
	}
	// 解法一 Time:O(n) Space:O(n)
	TreeNode* invertTree(TreeNode* root) {
		if (!root) return {};
		swap(root->left, root->right);
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};
