#include "pub_template.h"

namespace pub {
    // ��������
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
    // ɾ������
    ListNode* deleteNode(ListNode* head, int val) {
        if (head->val == val) return head->next;
        ListNode* cur = head->next, * pre = head;
        while (cur) {
            if (cur->val == val) break;
            cur = cur->next;
            pre = pre->next;
        }
        if(!cur) return head;   // ��֤cur��Ϊ��
        pre->next = cur->next;
        return head;
    }

    void printList(ListNode* head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
    // ���򹹽�������
    TreeNode* createTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;

        TreeNode* root = new TreeNode(nums[0]);
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i < nums.size()) {
            TreeNode* cur = q.front();
            q.pop();
            if (nums[i] != NULL) {   // NULL��ʾ�սڵ�
                cur->left = new TreeNode(nums[i]);
                q.push(cur->left);
            }
            i++;
            if (nums[i] != NULL) {
                cur->right = new TreeNode(nums[i]);
                q.push(cur->right);
            }
            i++;
        }
        return root;
    }
    // �����ӡ������
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
    // ǰ�����������
    void preOrderTree(TreeNode* root) {
        if (!root) return;
        cout << root->val << " ";
        preOrderTree(root->left);
        preOrderTree(root->right);
    }
    // �������������
    void inOrderTree(TreeNode* root) {
        if (!root) return;
        inOrderTree(root->left);
        cout << root->val << " ";
        inOrderTree(root->right);
    }
    // �������������
    void postOrderTree(TreeNode* root) {
        if (!root) return;
        postOrderTree(root->left);
        postOrderTree(root->right);
        cout << root->val << " ";
    }
    // �������������
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

    // Boolת��
    string Bool2Str(bool b) {
        return b ? "true" : "false";
    }
    // ��������
    int count_one(int n) {
        int cnt = 0;
        while (n) {
            n &= n - 1;
            cnt++;
        }
        return cnt;
    }
    // �����ǰ׺
    string longestCommonPrefix(const string& s1, const string& s2) {
        int len = min(s1.length(), s2.length()), i = 0;
        while (i < len && s1[i] == s2[i]) i++;
        return s1.substr(0, i);
    }
    // 
    unsigned int __builtin_ctz(unsigned int val) {
        unsigned long index; // ���ڴ洢λ��λ��
        if (_BitScanForward(&index, val)) {
            return index;
        }
        else {
            // ��������Ϊ0�������MSVC����Ϊ��δ����ģ������Ҫ�ر���
            return 32; // ����32λ�޷�������������32��ʾ����λ����0
        }
    }
}