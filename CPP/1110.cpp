/*
1110. Delete Nodes And Return Forest [Easy - 1511]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
	// ∫Û–Ú±È¿˙
	TreeNode* dfs(TreeNode* root, vector<TreeNode*>& forest, unordered_set<int>& to_delete) {
		if (!root) return nullptr;
		root->left = dfs(root->left, forest, to_delete);
		root->right = dfs(root->right, forest, to_delete);
		if (!to_delete.count(root->val)) return root;
		if (root->left) forest.push_back(root->left);
		if (root->right) forest.push_back(root->right);
		return nullptr;
	}
public:
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		vector<TreeNode*> forest;
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
		if (dfs(root, forest, to_delete_set)) forest.push_back(root);
		return forest;
	}
};

int main() {
	Solution sln;
	TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), new TreeNode(7)));
	vector<int> to_delete = { 3,5 };
	vector<TreeNode*> forest = sln.delNodes(root, to_delete);
	for (auto node : forest) cout << node->val << " ";
	return 0;
}