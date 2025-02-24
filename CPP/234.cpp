/*
234. Palindrome Linked List	[Esay - 3]
*/
#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges>
#include <functional>
#include <numeric>
#include <climits>
#include <cmath>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) :val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void printList(ListNode* head) {
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

void freeList(ListNode* head) {
	while (head) {
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
}

class Solution {
public:
	// 解法一 O(n) O(n)
	bool isPalindrome_1(ListNode* head) {
		vector<int> v;
		while (head) {
			v.push_back(head->val);
			head = head->next;
		}
		int len = v.size();
		for (int i = 0; i < len / 2; i++) {
			if (v[i] != v[len - i - 1]) return false;
		}
		return true;
	}
	// 解法二 快慢指针+反转链表 O(n) O(1)
	bool isPalindrome(ListNode* head) {
		ListNode* mid = head, * fast = head;
		while (fast && fast->next) {
			mid = mid->next;
			fast = fast->next->next;
		}
		// reverse mid
		ListNode* pre = nullptr, * cur = mid;
		while (cur) {
			ListNode* temp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = temp;
		}
		while (head && pre) {
			if (head->val != pre->val) return false;
			head = head->next;
			pre=pre->next;
		}
		return true;
	}
};

int main() {
	Solution sln;
	ListNode* head = new ListNode(1, new ListNode(2));
	ListNode* head2 = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
	ListNode* head3 = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(3, new ListNode(2, new ListNode(1))))));
	printList(head);
	cout << sln.isPalindrome(head) << endl;
	printList(head2);
	cout << sln.isPalindrome(head2) << endl;
	printList(head3);
	cout << sln.isPalindrome(head3) << endl;
	freeList(head);
	freeList(head2);
	freeList(head3);
	return 0;
}
