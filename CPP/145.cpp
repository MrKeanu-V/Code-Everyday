/*
145. Binary Tree Postorder Traversal [Easy]
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
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};

class Solution {
private:
	void postorder(TreeNode* root, vector<int>& res) {
		if (!root) return;
		postorder(root->left, res);
		postorder(root->right, res);
		res.emplace_back(root->val);
	}
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		postorder(root, res);
		return res;
	}
};

int main() {
	Solution sln;
	TreeNode* head = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
	vector<int> res = sln.postorderTraversal(head);
	for (auto e : res) cout << e << " ";
	return 0;
}