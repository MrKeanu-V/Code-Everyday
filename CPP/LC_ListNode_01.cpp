/*
LCR 136. Delete Node in a Linked List [Esay]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
public:
	ListNode* deleteNode(ListNode* head, int val) {
		if (head->val == val) return head->next;
		ListNode* cur = head;
		while (cur->next) {
			if (cur->next->val == val) break;
			cur = cur->next;
		}
		if (!cur->next) return head;// 保证无空指针
		cur->next = cur->next->next;
		return head;
	}

	void test() {
		vector<int> nums = { 4,5,1,9 };
		ListNode* head = createList(nums);
		printList(head);
		deleteNode(head, 5);
		printList(head);
	}
};

//int main() {
//	Solution().test();
//	return 0;
//}