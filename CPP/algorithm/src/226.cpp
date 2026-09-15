/*
226. Invert Binary Tree [Easy - 3]
*/
#include "fnt/fnt_solution.h"
#include "fnt/fnt_utils.h"
using namespace fnt;

class Solution226 : public BaseSolution {
public:
    FNT_SOLUTION_KEY("226")

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

	void test() override {
		TreeNode* root = new TreeNode(4);
		root->left = new TreeNode(2);
		root->right = new TreeNode(7);
		root->left->left = new TreeNode(1);
		root->left->right = new TreeNode(3);
		root->right->left = new TreeNode(6);
		root->right->right = new TreeNode(9);
		printTree(root);
		TreeNode* res = invertTree(root);
		printTree(res);
	}
};

FNT_REGISTER(Solution226);
