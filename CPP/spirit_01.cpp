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
    // �ⷨһ���ݹ�
    TreeNode* invertTree(TreeNode* root) {
        // �߽�����
        if (root == NULL) return NULL;
        // ������ǰ��������
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        // �ݹ齻����������
        invertTree(root->left);
        invertTree(root->right);
        // ���ص�ǰ���
        return root;
    }
    // ��ӡ������
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
    // ���������
    // ���룺[5,7,9,8,3,2,4]  5 7 9 8 3 2 4
    // �����[5,9,7,4,2,3,8]
    int val;
    vector<TreeNode*> nodes;
    while (cin >> val) {
        TreeNode* node = new TreeNode(val);
        nodes.push_back(node);
        // �������з�����ֹѭ��
        if (getchar() == '\n') break;
        if (cin.get() == '\n') break;
    }
   // ���㹹��������
    for (int i = 0; i < nodes.size(); i++) {
        if (i * 2 + 1 < nodes.size()) {
            nodes[i]->left = nodes[i * 2 + 1];
        }
        if (i * 2 + 2 < nodes.size()) {
            nodes[i]->right = nodes[i * 2 + 2];
        }
    }
    Solution sln;
    // ��ӡ������
    //for (auto node : nodes) cout << node->val << " ";
    // ��ת
    sln.invertTree(nodes[0]);
    //cout<<endl;
    // �����ӡ������
    sln.printTree(nodes[0]);
    // �ͷ��ڴ�
    for (auto node : nodes) delete node;
    return 0;
}