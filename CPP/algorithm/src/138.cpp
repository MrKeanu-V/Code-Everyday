/*
138. Copy List with Random Pointer [Medium - 6]
*/
#include "fnt/fnt_solution.h"
#include "fnt/fnt_utils.h"
using namespace fnt;

class Node {
public:
	int val;
	Node* next;
	Node* random;
	Node(int _val) {
		val = _val;
		next = nullptr;
		random = nullptr;
	}
	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};

class Solution138 : public BaseSolution {
public:
    FNT_SOLUTION_KEY("138")

	// 解法一 哈希+遍历 Time:O(n) Space:O(n)
	Node* copyRandomList_1(Node* head) {
		if (!head) return nullptr;
		unordered_map<Node*, Node*> mp;
		Node* cur = head, * dummy = new Node(cur->val);
		dummy->next = new Node(cur->val);
		Node* cur_new = dummy->next;
		mp[cur] = cur_new;
		while (cur->next) {
			cur = cur->next;
			Node* tmp = new Node(cur->val);
			cur_new->next = tmp;
			cur_new = cur_new->next;
			mp[cur] = cur_new;
		}
		cur = head;
		while (cur) {
			cur_new = mp[cur];
			cur_new->random = cur->random == nullptr ? nullptr : mp[cur->random];
			cur = cur->next;
		}
		return dummy->next;
	}
	// 解法一代码优化 Time:O(n) Space:O(n)
	Node* copyRandomList_2(Node* head) {
		if (!head) return {};
		unordered_map<Node*, Node*> mp;
		Node* cur = head, * dummy = new Node(-1), * cur2= dummy;
		while (cur) {
			cur2->next = new Node(cur->val);
			mp[cur] = cur2->next;
			cur = cur->next, cur2 = cur2->next;
		}
		while (head) {
			Node* tmp = mp[head];
			tmp->random = head->random == nullptr ? nullptr : mp[head->random];
			head = head->next;
		}
		return dummy->next;
	}
	// 解法二 奇偶链表 Time:O(n) Space:O(1)
	Node* copyRandomList_3(Node* head) {
		if (!head) return {};
		for (Node* cur = head; cur; cur = cur->next->next) cur->next = new Node(cur->val, cur->next, nullptr);
		for (Node* cur = head; cur; cur = cur->next->next) cur->next->random = cur->random ? cur->random->next : nullptr;
		Node* cur = head, * dummy = head->next;
		for (; cur->next->next; cur = cur->next) { // 拆分链表 
			Node* copy = cur->next;
			cur->next = copy->next; 
			copy->next = copy->next->next;
		}
		cur->next = nullptr;
		return dummy;
	}
	// 解法三 递归+记忆化 Time:O(n) Space:O(n)
	unordered_map<Node*, Node*> cachedNode;
	Node* copyRandomList(Node* head) {
		if (!head) return {};
		if (!cachedNode.count(head)) {
			Node* headNew = new Node(head->val);
			cachedNode[head] = headNew;
			headNew->next = copyRandomList(head->next);
			headNew->random = copyRandomList(head->random);
		}
		return cachedNode[head];
	}

	void test() override {
		Node* head = new Node(7);
		head->next = new Node(13);
		head->next->next = new Node(11);
		head->next->next->next = new Node(10);
		head->next->next->next->next = new Node(1);
		head->random = nullptr;
		head->next->random = head;
		head->next->next->random = head->next->next->next->next;
		head->next->next->next->random = head->next;
		head->next->next->next->next->random = head;
		Node* res = copyRandomList(head);
		while (res) {
			cout << res << " : " << res->val << " : " << res->random << endl;
			res = res->next;
		}
	}
};

FNT_REGISTER(Solution138);
