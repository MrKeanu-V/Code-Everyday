/*
LCR 052. 递增顺序搜索树 [Easy]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <numeric>
#include <unordered_map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	// constructor
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left) :val(x), left(left), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};

class Solution {
public:
	// 前序遍历
	void preorder(TreeNode* root, vector<int>& nums) {
		if (!root) return;
		nums.emplace_back(root->val);
		preorder(root->left, nums);
		preorder(root->right, nums);
	}

	// 中序遍历
	void inorder(TreeNode* root, vector<int>& nums) {
		if (!root) return;
		inorder(root->left, nums);
		nums.emplace_back(root->val);
		inorder(root->right, nums);
	}

	// 后序遍历
	void postorder(TreeNode* root, vector<int>& nums) {
		if (!root) return;
		postorder(root->left, nums);
		postorder(root->right, nums);
		nums.emplace_back(root->val);
	}

	TreeNode* increasingBST(TreeNode* root) {
		vector<int> nums;
		inorder(root, nums);

		TreeNode* dummy = new TreeNode(-1);
		TreeNode* cur = dummy;

		for (auto& e : nums) {
			cur->right = new TreeNode(e);
			cur = cur->right;
		}
		
		return dummy->right;
	}
};

int main() {
	Solution sln;
	TreeNode* root = new TreeNode(5, new TreeNode(3, new TreeNode(2), new TreeNode(4)), new TreeNode(6, nullptr, new TreeNode(8, new TreeNode(7), new TreeNode(9))));
	TreeNode* res = sln.increasingBST(root);
	while (res) {
        cout << res->val << " ";
		res = res->right;
	}
	return 0;
}
