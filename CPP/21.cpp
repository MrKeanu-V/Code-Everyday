/*
21. Merge Two Sorted Lists [Easy - 3]
*/
#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges>
#include <functional>
#include <numeric>
#include <climits>
#include <cmath>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) :val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    // 解法一 迭代
    ListNode* mergeTwoLists_1(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr, * tail = nullptr;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                if (head == nullptr) {
                    head = tail = new ListNode(list1->val);
                }
                else {
                    tail->next = new ListNode(list1->val);
                    tail = tail->next;
                }
                list1 = list1->next;
            }
            else {
                if (!head) {
                    head = tail = new ListNode(list2->val);
                }
                else{
                    tail->next = new ListNode(list2->val);
                    tail = tail->next;
                }
                list2 = list2->next;
            }
        }
        if (list1) {
            if (!head) return list1;
            while (list1) {
                tail->next = new ListNode(list1->val);
                tail = tail->next;
                list1 = list1->next;
            }
        }
        if (list2) {
            if (!head) return list2;
            while (list2) {
                tail->next = new ListNode(list2->val);
                tail = tail->next;
                list2 = list2->next;
            }
        }
        return head;
    }
    // 解法二 迭代优化 哨兵结点
    ListNode* mergeTwoLists_2(ListNode* list1, ListNode* list2) {
        ListNode dummy{};
        ListNode* tail = &dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }
    // 解法三 递归
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
};

void printList(ListNode* root) {
    while (root) {
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
}

void test() {
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* root = Solution().mergeTwoLists(list1, list2);
    printList(list1);
    printList(list2);
    printList(root);
}

int main() {
    test();
    return 0;
}
