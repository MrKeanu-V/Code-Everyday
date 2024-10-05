/*
141. Linked List Cycle [Easy 2]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	// constructor
	ListNode() :val(0), next(nullptr) {};	// nullptr在C++11后引入，是类型安全的，而NULL则是宏定义为0或者空，不是类型安全用于C++11以前
	ListNode(int x) :val(x), next(nullptr) {};
	ListNode(int x, ListNode* next) :val(x), next(next) {};
};

/*
链表查找类方法迅速思考两种，一是快慢指针，二是哈希表
	快慢指针时间复杂度为O(n)，空间复杂度为O(1)
	哈希表时间复杂度为O(n)，空间复杂度为O(n)
快慢指针的思想是，快指针每次走两步，慢指针每次走一步，
如果存在环，则快指针会追上慢指针，否则快指针会先到达链表尾部
可以从相对位移的角度思考，快指针相对慢指针每次移动一步，慢指针原地不动，因此只要存在环，两者必然相遇
*/
class Solution {
public:
	// 解法一 快慢指针
	bool hasCycle1(ListNode* head) {
		// 边界条件
		if (head == nullptr) return false;

		ListNode* slow = head, * fast = head->next;

		while (slow!=fast) {
			if (fast == nullptr || fast->next == nullptr)
				return false;
			slow = slow->next;
			fast = fast->next->next;
		}

		return true;
	}
	// 解法二 哈希表
	bool hasCycle(ListNode* head) {
		unordered_set<ListNode*> hashset;
		while (head != nullptr) {
			if (hashset.count(head)) return true;
			hashset.insert(head);
			head = head->next;
		}
		return false;
	}
};

int main() {
	Solution sln;
	//ListNode* head = nullptr;
	ListNode* head = new ListNode(1);
	//head->next = new ListNode(2);	
	//head->next->next = new ListNode(3);
	//head->next->next->next = head->next;
	cout << sln.hasCycle(head) << endl;
	return 0;
}