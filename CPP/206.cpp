/*
206. Reverse Linked List [Easy - 3]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) :val(x), next(next) {}
};

class Solution {
public:
	// 解法一 暴力
	ListNode* reverseList(ListNode* head) {
		ListNode* cur = head, * pre = nullptr;
		while (cur) {
   			ListNode* tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}
		return pre;
	}
};

int main() {
	Solution sln;
	ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
	head = sln.reverseList(head);
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	return 0;
}