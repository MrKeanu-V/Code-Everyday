/*
144. Binary Tree Preorder Traversal [Easy]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	// constructor
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};

class Solution {
private:
	void preorder(TreeNode* root, vector<int>& res) {
		if (!root) return;
		res.emplace_back(root->val);
		preorder(root->left, res);
		preorder(root->right, res);
	}
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		preorder(root, res);
		return res;
	}
};

int main() {
	Solution sln;
	TreeNode* head = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
    vector<int> res = sln.preorderTraversal(head);
	for (auto e : res)
		cout << e << " ";
	return 0;
}