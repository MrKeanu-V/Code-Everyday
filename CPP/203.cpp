/*
203. Remove Linked List Elements [Easy]
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	// constructor
	ListNode() :val(0), next(nullptr) {}
	ListNode(int x) :val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) :val(x), next(next) {}
};

class Solution {
public:
	// нчиз╠Ь╫А╣Ц
	ListNode* removeElements1(ListNode* head, int val) {
		ListNode* cur = head, * pre = nullptr;

		while (cur) {
			if (cur->val == val) {
				if (pre) {
					pre->next = cur->next;
				}
				else {
					head = cur->next;
				}
			}
			else {
				pre = cur;
			}
			cur = cur->next;
		}

		return head;
	}
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* cur = new ListNode(INT_MAX, head),* dummy = new ListNode(0, cur);

		while (cur->next) {
			auto next = cur->next;
			if (next->val == val) {
				cur->next = next->next;
				delete next;
			}
			cur = cur->next;
		}

		return dummy->next->next;
	}
};

int main() {
	Solution sln;
	ListNode* head = new ListNode(1, new ListNode(2, new ListNode(6, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))))));
	int val = 1;
	ListNode* cur = sln.removeElements(head, val);
	while (cur) {
		cout << cur->val << " ";
		cur = cur->next;
	}
	return 0;
}