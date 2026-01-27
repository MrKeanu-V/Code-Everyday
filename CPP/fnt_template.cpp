/**
 * @file pub_template.cpp
 * @brief framework for my algorithms problem solving
 * 
 * @GitMsg Template: use file desc, and algorithm category organized by |.
*  eg: git commit -m "739. Daily Temperatures [Medium - 6 - Brute|MonoStack]"
*/
#include "fnt_template.h"

// Foundation
namespace fnt {
    // 构造链表
    ListNode* createList(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        for (int i = 0; i < nums.size(); i++) {
            cur->next = new ListNode(nums[i]);
            cur = cur->next;
        }
        return dummy->next;
    }
    // 删除链表
    ListNode* deleteNode(ListNode* head, int val) {
        if (head->val == val) return head->next;
        ListNode* cur = head->next, * pre = head;
        while (cur) {
            if (cur->val == val) break;
            cur = cur->next;
            pre = pre->next;
        }
        if(!cur) return head;   // 保证cur不为空
        pre->next = cur->next;
        return head;
    }
	// 释放链表
	void freeList(ListNode* head){
		while (head) {
			ListNode* tmp = head;
            // 避免重复释放
            try {
                head = head->next;
                delete tmp;
            }
            catch (const std::exception& e) {
                //cout << e.what() << endl;
            }
		}
	}

    void printList(ListNode* head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
    // 层序构建二叉树
    TreeNode* createTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;

        TreeNode* root = new TreeNode(nums[0]);
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i < nums.size()) {
            TreeNode* cur = q.front();
            q.pop();
            if (nums[i] != NULL) {   // NULL表示空节点
                cur->left = new TreeNode(nums[i]);
                q.push(cur->left);
            }
            i++;
            if (i >= nums.size()) break;
            if (nums[i] != NULL) {
                cur->right = new TreeNode(nums[i]);
                q.push(cur->right);
            }
            i++;
        }
        return root;
    }
    // 层序打印二叉树
    void printTree(TreeNode* root) {
        if (!root) {
            cout << "empty tree" << endl;
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            cout << cur->val << " ";
            if (cur->left) q.push(cur->left);
            else cout << "NULL ";
            if (cur->right) q.push(cur->right);
            else cout << "NULL ";
        }
        cout << endl;
    }
    // 前序遍历二叉树
    void preOrderTree(TreeNode* root) {
        if (!root) return;
        cout << root->val << " ";
        preOrderTree(root->left);
        preOrderTree(root->right);
    }
    // 中序遍历二叉树
    void inOrderTree(TreeNode* root) {
        if (!root) return;
        inOrderTree(root->left);
        cout << root->val << " ";
        inOrderTree(root->right);
    }
    // 后序遍历二叉树
    void postOrderTree(TreeNode* root) {
        if (!root) return;
        postOrderTree(root->left);
        postOrderTree(root->right);
        cout << root->val << " ";
    }
    // 层序遍历二叉树
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
                else vals.push_back(INT_MIN);
                if (node->right) q.push(node->right);
                else vals.push_back(INT_MIN);
            }
            res.emplace_back(vals);
        }
        return res;
    }

    // Bool转换
    string Bool2Str(bool b) {
        return b ? "true" : "false";
    }
    // 汉明重量
    int count_one(int n) {
        int cnt = 0;
        while (n) {
            n &= n - 1;
            cnt++;
        }
        return cnt;
    }
    // 最长公共前缀
    string longestCommonPrefix(const string& s1, const string& s2) {
        int len = min(s1.length(), s2.length()), i = 0;
        while (i < len && s1[i] == s2[i]) i++;
        return s1.substr(0, i);
    }
    // 
    unsigned int __builtin_ctz(unsigned int val) {
        unsigned long index; // 用于存储位的位置
        if (_BitScanForward(&index, val)) {
            return index;
        }
        else {
            // 对于输入为0的情况，MSVC的行为是未定义的，因此需要特别处理。
            return 32; // 假设32位无符号整数，返回32表示所有位都是0
        }
    }
}