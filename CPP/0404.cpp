/*
04.04 Check Balance Icci [Esay]
*/
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <ranges>
using namespace std;

struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :value(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :value(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :value(x), left(left), right(right) {}
};

class Solution {
private:
	bool balanced = true;
	int dfs(TreeNode* root, int depth) {
		if (root == nullptr) return depth;
		depth++;
		int leftDepth = dfs(root->left, depth);
		int rightDepth = dfs(root->right, depth);
		if (abs(leftDepth - rightDepth) > 1) balanced = false;
		return max(leftDepth, rightDepth);
	}
public:
	// DFS
	bool isBalanced(TreeNode* root) {
		dfs(root, 0);
		return balanced;
	}
};

int main() {
	Solution sln;
	TreeNode* root = new TreeNode(3);	// [3,9,20,null,null,15,7] true
	if (sln.isBalanced(root)) cout << "true" << endl;
	else cout << "false" << endl;
	return 0;
}