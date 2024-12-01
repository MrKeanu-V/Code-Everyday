/*
Invert a binary tree.
*/
#include <iostream>  
#include <queue>  
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 解法一：递归
    TreeNode* invertTree(TreeNode* root) {
        // 边界条件
        if (root == NULL) return NULL;
        // 交换当前左右子树
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        // 递归交换左右子树
        invertTree(root->left);
        invertTree(root->right);
        // 返回当前结点
        return root;
    }
    // 打印二叉树
    void printTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";
            if (node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
        }
    }
};

int my_main() {
    // 输入二叉树
    // 输入：[5,7,9,8,3,2,4]  5 7 9 8 3 2 4
    // 输出：[5,9,7,4,2,3,8]
    int val;
    vector<TreeNode*> nodes;
    while (cin >> val) {
        TreeNode* node = new TreeNode(val);
        nodes.push_back(node);
        // 读到换行符，终止循环
        if (getchar() == '\n') break;
        if (cin.get() == '\n') break;
    }
   // 按层构建二叉树
    for (int i = 0; i < nodes.size(); i++) {
        if (i * 2 + 1 < nodes.size()) {
            nodes[i]->left = nodes[i * 2 + 1];
        }
        if (i * 2 + 2 < nodes.size()) {
            nodes[i]->right = nodes[i * 2 + 2];
        }
    }
    Solution sln;
    // 打印二叉树
    //for (auto node : nodes) cout << node->val << " ";
    // 反转
    sln.invertTree(nodes[0]);
    //cout<<endl;
    // 按层打印二叉树
    sln.printTree(nodes[0]);
    // 释放内存
    for (auto node : nodes) delete node;
    return 0;
}