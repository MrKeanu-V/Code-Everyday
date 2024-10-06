/*
147. Insertion Sort List [Medium]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int x) :val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) :val(x), next(next) {}
};

class Solution {
public:
	// 解法一 插入排序 原链表
	ListNode* insertionSortList(ListNode* head) {
		// 边界条件
		if (!head) return head;
		ListNode* dummy = new ListNode(0, head);
		ListNode* cur = head->next, * last = head;
		while (cur) {
			if (cur->val >= last->val) last = cur;
			else {
				ListNode* pre = dummy;
				while (pre->next->val < cur->val) pre = pre->next;
				last->next = cur->next;
				cur->next = pre->next;
				pre->next = cur;
			}
			cur = last->next;
		}
		return dummy->next;
	}
};

int main() {
	Solution sln;
	ListNode* head = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
	ListNode* res = sln.insertionSortList(head);
	while (res) {
		cout << res->val << " ";
		res = res->next;
	}
	return 0;
}