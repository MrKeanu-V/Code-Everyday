/*
������Ϸ ����1
����������������㣬�ҵ�����������ȡ�
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
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param root TreeNode��
//     * @param p int����
//     * @param q int����
//     * @return int����
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