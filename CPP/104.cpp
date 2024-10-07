/*
104. Maximum Depth of Binary Tree [Easy - 3]
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
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};

class Solution {
private:
	int ans = 0;
	void dfs(TreeNode* root, int depth) {
		if (!root) return;
		depth++;
		dfs(root->left, depth);
		dfs(root->right, depth);
		ans = max(ans, depth);
	}
public:
	// 解法一 自底向上
	int maxDepth1(TreeNode* root) {
		if (!root) return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
	// 解法二 自顶向下
	int maxDepth(TreeNode* root) {
		dfs(root, 0);
		return ans;
	}
};

int main() {
	Solution sln;
	TreeNode* root = new TreeNode(1, new TreeNode(2), nullptr);//new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
	cout << sln.maxDepth(root) << endl;
	return 0;
}