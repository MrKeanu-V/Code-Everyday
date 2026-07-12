/*
94. Binary Tree Inorder Traversal [Easy]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	// constructor
	TreeNode() :val(-1), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left) :val(x), left(left), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};

class Solution {
public:
	void inorder(TreeNode* root, vector<int>& nums) {
		if (root == nullptr) return;
		inorder(root->left, nums);
		nums.emplace_back(root->val);
		inorder(root->right, nums);
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> nums;
		inorder(root, nums);
		return nums;
	}
};

int main() {
	Solution sln;
	TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
	vector<int> res = sln.inorderTraversal(root);
	for_each(res.begin(), res.end(), [](int x) {cout << x << " "; });
	return 0;
}