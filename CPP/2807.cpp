/*
2807. Insert Greatest Common Divisors in Linked List [Medium]
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
private:
	int gcd(int a, int b) {
		if (b == 0) return a;
        return gcd(b, a % b);
	}
public:
	ListNode* insertGreatestCommonDivisors1(ListNode* head) {
		ListNode* cur = head->next, * pre = head;
		while (cur) {
			ListNode* tmp = new ListNode(gcd(pre->val, cur->val), cur);	// C++17中引入了最大公约数gcd函数，但vc6不支持
			pre->next = tmp;
			pre = cur;
			cur = cur->next;
		}
		return head;
	}

	ListNode* insertGreatestCommonDivisors(ListNode* head) {
		for (auto cur = head; cur->next; cur = cur->next->next)
			cur->next = new ListNode(gcd(cur->val, cur->next->val), cur->next);
		return head;
	}
};

int main() {
	Solution sln;
	ListNode* head = new ListNode(2, new ListNode(3, new ListNode(6, new ListNode(7))));
	head = sln.insertGreatestCommonDivisors(head);
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	return 0;
}