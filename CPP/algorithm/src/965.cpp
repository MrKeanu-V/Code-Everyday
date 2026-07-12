/*
965. Univalued Binary Tree [Easy - 1178]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};

class Solution {
private:
	int flag;
	bool dfs(TreeNode* root) {
		if (!root) return true;
		if (root->val != flag) return false;
		return dfs(root->left) && dfs(root->right);
	}
public:
	// Top-Down
	bool isUnivalTree(TreeNode* root) {
		flag = root->val;
		return dfs(root);
	}
};

int main() {
	Solution sln;
	TreeNode* root = new TreeNode(1, new TreeNode(1, new TreeNode(1), new TreeNode(1)), new TreeNode(1, new TreeNode(1), new TreeNode(1)));
	cout << sln.isUnivaluedTree(root) << endl;
	return 0;
}