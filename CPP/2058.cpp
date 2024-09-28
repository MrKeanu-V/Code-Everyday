/*
2058. Find The Minimum And Maximum Number Of Nodes Between Critical Points [Medium - 1311]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	// ¹¹Ôìº¯Êý
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) :val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) :val(x), next(next) {}
};

class Solution {
public:
	bool isCritical(int x, int y, int z) {
		//return (cur->val > cur->next->val && cur->next->val < cur->next->next->val) || (cur->val < cur->next->val && cur->next->val > cur->next->next->val);
		return y > max(x, z) || y < min(x, z);
	}
	vector<int> nodesBetweenCriticalPoints(ListNode* head) {
		int minDist = -1, maxDist = -1;
		int first = -1, last = -1, pos = 0;
		ListNode* cur = head;
		while (cur->next->next) {
			if (isCritical(cur->val, cur->next->val, cur->next->next->val)) {
				if (last != -1) {
					minDist = (minDist == -1 ? pos - last : min(minDist, pos - last));
					maxDist = max(maxDist, pos - first);
				}
				if (first == -1) {
                    first = pos;
				}
				last = pos;
			}
			cur = cur->next;
			pos++;
		}
		return { minDist, maxDist };
	}
};

int main() {
	Solution sln;
	//ListNode* head = new ListNode(3, new ListNode(1, new ListNode(5, new ListNode(5, new ListNode(2, new ListNode(4, new ListNode(6)))))));
	ListNode* head = new ListNode(4, new ListNode(2, new ListNode(4, new ListNode(1))));
    vector<int> res = sln.nodesBetweenCriticalPoints(head);
	for (auto& x : res)
		cout << x << " ";
	return 0;
}