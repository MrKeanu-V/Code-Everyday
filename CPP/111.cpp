/*
111. Minimum Depth of Binary Tree [Easy - 3]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
	TopDown�Զ����£��ȷ��ʽڵ㣬�ٷ���������ÿ���ڵ��ڵݹ���������ӽڵ�֮ǰ������
	BottomUp�Ե����ϣ��ȷ����������ٷ��ʽڵ㣻ÿ���ڵ��ڵݹ���������ӽڵ�֮�󱻴���
*/
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};

class Solution {
private:
	int ans = INT_MAX;
	void dfs(TreeNode* root, int depth) {
		if (!root) return;
		depth++;
		if (!root->left && !root->right) ans = min(ans, depth);
		dfs(root->left, depth);
		dfs(root->right, depth);
	}
public:
	// �ⷨһ �Զ�����
	int minDepth(TreeNode* root) {
		dfs(root, 0);
		return root ? ans : 0;
	}
	// �ⷨ�� �Ե����� ��������ڵ㴦��
	int minDepth2(TreeNode* root) {
		if (!root) return 0;
		if (!root->left) return minDepth(root->right) + 1;
		if (!root->right) return minDepth(root->left) + 1;
		return min(minDepth(root->left), minDepth(root->right)) + 1;
	}
};

int main() {
	Solution sln;
	TreeNode* head = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
	cout << sln.minDepth(head) << endl;
	return 0;
}