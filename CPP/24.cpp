/*
24. Swap Nodes in Pairs [Medium - 4]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
	// 解法一 递推 Time:O(n) Space:O(1)
	ListNode* swapPairs_1(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode* dummy = new ListNode(0, head), * pre = dummy, * cur = head;
		while (cur != nullptr && cur->next != nullptr) {
			pre->next = cur->next;
			ListNode* tmp = cur->next->next;
			cur->next->next = cur;
			cur->next = tmp;
			pre = cur;
			cur = cur->next;
		}
		return dummy->next;
	}
	ListNode* swapPairs_2(ListNode* head) {
		ListNode dummy(0, head);
		ListNode* node0 = &dummy, * node1 = head;
		while (node1 && node1->next) {
			ListNode* node2 = node1->next;
			ListNode* node3 = node2->next;
			node0->next = node2;
			node2->next = node1;
			node1->next = node3;
			node0 = node1;
			node1 = node3;
		}
		return dummy.next;
	}
	// 解法二 递归 Time:O(n) Space:O(n)
	ListNode* swapPairs(ListNode* head) {
		if (head || head->next) return head;
		ListNode* node1 = head, * node2 = head->next;
		ListNode* node3 = node2->next;
		node1->next = swapPairs(node3);
		node2->next = node1;
		return node2;
	}
};