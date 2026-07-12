/*
543. Diameter of Binary Tree [Easy - 3]
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
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
	int dfs(TreeNode* root, int& res) {
		if (!root) return 0;
		int left = dfs(root->left, res);
		int right = dfs(root->right, res);
		int maxLen = left + right;
		res=max(res,maxLen);	// 在归并过程中更新最大值
		return max(left, right) + 1;
	}
public:
	int diameterOfBinaryTree(TreeNode* root) {
		int res = 0;
		dfs(root, res);
		return res;
	}
	int diameterOfBinaryTree2(TreeNode* root) {
		int res = 0;
		auto dfs = [&](auto&& dfs, TreeNode* root)->int {	// 函数变量
			if (!root) return -1;
			int left = dfs(dfs, root->left) + 1, right = dfs(dfs, root->right) + 1;
			res = max(res, left + right);
			return max(left, right);
		};
		dfs(dfs, root);
		return res;
	}
};

int main() {
	Solution sln;
	TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
	cout << sln.diameterOfBinaryTree(root) << endl;
	return 0;
}