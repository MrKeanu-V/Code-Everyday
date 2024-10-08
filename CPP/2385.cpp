/*
2385. Amount of Time for Binary Tree to Be Infected [Medium - 1711]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* hashmap[100001];
class Solution {
private:
	int start;
	TreeNode* startNode;
	void dfs(TreeNode* node, TreeNode* parent) {
		if (!node) return;
		hashmap[node->val] = parent;
		if (node->val == start) startNode = node;
		dfs(node->left, node);
		dfs(node->right, node);
	}

	int getTime(TreeNode* cur, TreeNode* from) {
		if (!cur) return 0;
		int depth = 0;
		if(cur->left!=from) depth = max(depth, getTime(cur->left, cur));
		if (cur->right != from) depth = max(depth, getTime(cur->right, cur));
		if(hashmap[cur->val]!= from) depth = max(depth, getTime(hashmap[cur->val], cur));
		return depth + 1;
	}

public:
	// 解法一 DFS+模拟 TLE
	int amountOfTime(TreeNode* root, int start) {
		this->start = start;
		dfs(root, nullptr);
		return getTime(startNode, startNode)-1;
	}
};

int main() {
	Solution sln;
	TreeNode* root = new TreeNode(1, new TreeNode(5, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), new TreeNode(7)));
	cout << sln.amountOfTime(root, 3) << endl;
	return 0;
}