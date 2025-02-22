#pragma once

/*
19. Remove Nth Node From End of List [Medium - 3]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
	// 解法一： 暴力法 Time:O(n) Space:O(1)
	ListNode* removeNthFromEnd_1(ListNode* head, int n) {
		ListNode* dummy = new ListNode(0, head);
		int len = 0;
		while (head) {
			len++;
			head = head->next;
		}
		head = dummy;
		for (int i = 0; i < len - n; i++) {
			head = head->next;
		}
		ListNode* temp = head->next;
		head->next = temp ? temp->next : nullptr;
		//if(temp) delete temp;
		return dummy->next;
	}
	// 解法二：快慢指针 Time:O(n) Space:O(1)
	ListNode* removeNthFromEnd_2(ListNode* head, int n) {

	}
	// 解法三：栈 Time:O(n) Space:O(n)
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		stack<ListNode*> s;
		ListNode* dummy = new ListNode(0, head);
		ListNode* cur = dummy;
		while (cur) {
			s.push(cur);
			cur = cur->next;
		}
		while (n--) s.pop();
		ListNode* temp = s.top();
		temp->next = temp->next->next;
		return dummy->next;
	}

	void test() {
		ListNode* head = new ListNode(1);
		removeNthFromEnd(head, 1);
		printList(head);
		cout << endl;
		head = new ListNode(1, new ListNode(2));
		removeNthFromEnd(head, 2);
		printList(head);
	}
};
