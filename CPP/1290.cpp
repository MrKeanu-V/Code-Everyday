/*
1290. Convert Binary Number in a Linked List to Integer [Medium-1151]
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	// ¹¹Ôìº¯Êý
	ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	int getDecimalValue(ListNode* head) {
		int res = 0;
		while (head) {
            //res = (res << 1) + head->val;
			res = res * 2 + head->val;
			head = head->next;
		}
		return res;
	}
};

int main() {
	ListNode* head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);
	Solution sln;
	cout<<sln.getDecimalValue(head)<<endl;
    return 0;
}