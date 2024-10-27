/*
极致游戏 笔试1
给定二叉树两个结点，找到最近公共祖先。
*/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <functional>
#include <ranges>
using namespace std;


//struct TreeNode {
//    int val;
//    struct TreeNode *left;
//    struct TreeNode *right;
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* left,TreeNode* right):val(x),left(left), right(right){}
//};
// 
//class Solution {
//private:
//    bool dfs(TreeNode* root, unordered_set<TreeNode*>& path, int target) {
//        if (root == nullptr) return false;
//        if (root->val == target) return true;
//        bool l = dfs(root->left, path, target);
//        bool r = dfs(root->right, path, target);
//        if (l || r) path.insert(root);
//        return l || r;
//    }
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param root TreeNode类
//     * @param p int整型
//     * @param q int整型
//     * @return int整型
//     */
//    int lowestCommonAncestor(TreeNode* root, int p, int q) {
//        // write code here
//        unordered_set<TreeNode*> path_p, path_q;
//        dfs(root, path_p, p);
//        dfs(root, path_q, q);
//        for (auto node : path_p)
//            if (path_q.find(node) != path_q.end()) return node->val;
//        return root->val;
//    }
//};
//
//int main() {
//    Solution sln;
//    // {3,5,1,6,2,0,8,#,#,7,4},5,1
//    TreeNode* root = new TreeNode(3,new TreeNode(5,new TreeNode(6),new TreeNode(2,new TreeNode(4),new TreeNode(7))), new TreeNode(1));
//    int p = 5, q = 1;
//    cout << sln.lowestCommonAncestor(root, p, q) << endl;
//    return 0;
//}