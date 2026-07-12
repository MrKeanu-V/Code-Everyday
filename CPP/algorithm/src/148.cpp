/*
148. Sort List [Medium - 6]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
private:
    ListNode* middle(ListNode* head) {
        ListNode* slow = head, * fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
public:
    // 解法一 数组+排序 Time: O(nlogn) Space: O(n)
    ListNode* sortList_1(ListNode* head) {
        if (!head || !head->next) return head;
        vector<int> values;
        for (ListNode* cur = head; cur; cur = cur->next) {
            values.push_back(cur->val);
        }
        sort(values.begin(), values.end());
        ListNode* cur = head;
        for (int i = 0; i < values.size(); ++i, cur = cur->next) {
            cur->val = values[i];
        }
        return head;
    }
    // 解法二 归并排序 Time: O(nlogn) Space: O(logn)
    ListNode* sortList_2(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* mid = middle(head);
        ListNode* l1 = head, * l2 = mid->next;
        mid->next = nullptr;
        return mergeTwoLists(sortList_2(l1), sortList_2(l2));
    }
};