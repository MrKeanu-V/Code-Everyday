/*
101. Symmetric Tree	[Easy - 3]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
	void inOrder(TreeNode* root, vector<int>& nums) {
		if (!root) {
			nums.push_back(INT_MIN);
			return;
		}
		inOrder(root->left, nums);
		nums.push_back(root->val);
		inOrder(root->right, nums);
	}

	bool isSymmetric_1(TreeNode* root) {
		vector<int> nums;
		inOrder(root, nums);
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			if (nums[l] != nums[r]) return false;
			l++, r--;
		}
		return true;
	}

	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!p || !q) return p == q;
		return p->val == q->val && isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
	}

	bool isSymmetric(TreeNode* root) {
		return !root || isSameTree(root->left, root->right);
	}

	void test() {
		vector<int> nums = { 1,2,2,3,4,4,3 };
		TreeNode* root = createTree(nums);
		inOrderTree(root);
		string ans = isSymmetric(root) ? "true" : "false";
		cout << ans << endl;

		nums = { 1,2,2 ,NULL,3,NULL,3 };
		root = createTree(nums);
		inOrderTree(root);
		ans = isSymmetric(root) ? "true" : "false";
		cout << Bool2Str(isSymmetric(root)) << endl;

		nums = { 1,2,2,2,NULL,2 };
		print1DVector(nums);
		//root = createTree(nums);
		inOrderTree(root);
		cout << Bool2Str(isSymmetric(root)) << endl;
	}
};

int main() {
	Solution().test();
	return 0;
}