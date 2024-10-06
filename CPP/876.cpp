/*
876. Middle of the Linked List [Easy - 1232]
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
	ListNode(int x) : val(x), next(nullptr) {};
	ListNode(int x, ListNode* next) :val(x), next(next) {};
};

class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		ListNode* slow = head, * fast = head;
		while(fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
};

int main() {
	Solution sln;
	ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
	ListNode* mid = sln.middleNode(head);
	cout << mid->val << endl;
	return 0;
}