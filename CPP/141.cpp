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
	ListNode() :val(0), next(nullptr) {};	// nullptr��C++11�����룬�����Ͱ�ȫ�ģ���NULL���Ǻ궨��Ϊ0���߿գ��������Ͱ�ȫ����C++11��ǰ
	ListNode(int x) :val(x), next(nullptr) {};
	ListNode(int x, ListNode* next) :val(x), next(next) {};
};

/*
��������෽��Ѹ��˼�����֣�һ�ǿ���ָ�룬���ǹ�ϣ��
	����ָ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)
	��ϣ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(n)
����ָ���˼���ǣ���ָ��ÿ������������ָ��ÿ����һ����
������ڻ������ָ���׷����ָ�룬�����ָ����ȵ�������β��
���Դ����λ�ƵĽǶ�˼������ָ�������ָ��ÿ���ƶ�һ������ָ��ԭ�ز��������ֻҪ���ڻ������߱�Ȼ����
*/
class Solution {
public:
	// �ⷨһ ����ָ��
	bool hasCycle1(ListNode* head) {
		// �߽�����
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
	// �ⷨ�� ��ϣ��
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