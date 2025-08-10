/*
226. Invert Binary Tree [Easy - 3]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
	// �ⷨһ �ݹ� Time:O(n) Space:O(n)
	TreeNode* invertTree_1(TreeNode* root) {
		if (!root) return {};
		TreeNode* tmp = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(tmp);
		return root;
	}
	// �ⷨһ Time:O(n) Space:O(n)
	TreeNode* invertTree(TreeNode* root) {
		if (!root) return {};
		swap(root->left, root->right);
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};
