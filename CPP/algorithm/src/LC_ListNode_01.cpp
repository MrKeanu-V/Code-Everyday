/*
LCR 136. Delete Node in a Linked List [Esay]
*/
#include "fnt/fnt_solution.h"
#include "fnt/fnt_utils.h"
using namespace fnt;

class Solution_LCR136 : public BaseSolution {
public:
    FNT_SOLUTION_KEY("LCR136")

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

	void test() override {
		vector<int> nums = { 4,5,1,9 };
		ListNode* head = createList(nums);
		printList(head);
		deleteNode(head, 5);
		printList(head);
	}
};

FNT_REGISTER(Solution_LCR136);
