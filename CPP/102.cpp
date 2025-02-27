/*
102. Binary Tree Level Order Traversal [Medium - 4]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
    // 解法一 BFS Time: O(n) Space: O(n)
    vector<vector<int>> levelOrder_1(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            queue<TreeNode*> nodes;
            vector<int> level;
            while (!q.empty()) {
                TreeNode* node = q.front();
                nodes.push(node);
                level.push_back(node->val);
                q.pop();
            }
            while (!nodes.empty()) {
                TreeNode* node = nodes.front();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                nodes.pop();
            }
            res.push_back(level);
        }
        return res;
    }
    // 解法一 BFS优化 Time: O(n) Space: O(n)
    vector<vector<int>> levelOrder_02(TreeNode* root) {
        if (!root) return {};   //C++11引入的空列表初始化，根据函数返回类型确定空返回值
        vector<vector<int>> res;
        vector<TreeNode*> nodes = { root };
        while (!nodes.empty()) {
            vector<TreeNode*> next;
            vector<int> level;
            for (auto node : nodes) {
                level.push_back(node->val);
                if (node->left) next.push_back(node->left);
                if (node->right) next.push_back(node->right);
            }
            res.push_back(level);
            nodes = move(next); //使用移动语义，避免深拷贝
        }
        return res;
    }
    // 解法一 BFS优化2 Time: O(n) Space: O(n)
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};   
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> vals;
            for (int n = q.size(); n--;) {
                auto node = q.front();
                q.pop();
                vals.push_back(node->val);
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.emplace_back(vals);
        }
        return res;
    }

    void test() {
        vector<int> nums = { 3,9,20,NULL, NULL, 15,7 };
        TreeNode* root = createTree(nums);
        printTree(root);
        vector<vector<int>> res = levelOrder(root);
        print2DVector(res);
    }
};

//int main() {
//    Solution().test();
//    return 0;
//}