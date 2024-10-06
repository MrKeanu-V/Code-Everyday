/*
142. Linked List Cycle II [Medium - 2]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	//constructor
	ListNode(int x) :val(x), next(nullptr) {};
	ListNode(int x, ListNode* next) : val(x), next(next) {};
};

class Solution {
public:
	// 解法一 哈希表
	ListNode* detectCycle1(ListNode* head) {
		unordered_set<ListNode*> hashset;
		while (head != nullptr) {
			if (hashset.count(head)) return head;
			hashset.insert(head);
			head = head->next;
		}
		return nullptr;
	}
	// 解法二 快慢指针
	ListNode* detectCycle(ListNode* head) {
		ListNode* slow = head, * fast = head;
		while (fast&& fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				while (head != slow) {
					head = head->next;
					slow = slow->next;
				}
				return slow;
			}
		}
		return nullptr;
	}
};

int main() {
	Solution sln;
	ListNode* head = nullptr;
	/*ListNode* head = new ListNode(3, new ListNode(2, new ListNode(0, new ListNode(-4))));
    head->next->next->next->next = head->next;*/
	ListNode* ans = sln.detectCycle(head);
	if (ans == nullptr)
		cout << "NULL" << endl;
	else
		cout << ans->val << endl;
	return 0;
}