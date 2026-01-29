/*
25. Reverse nodes in k-group [Hard - 4]
*/
#include "fnt_template.h"
#include "fnt_solution.h"
using namespace fnt;

class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (k == 1)
            return head;
        std::stack<ListNode*> m_stack;
        ListNode* cur = head;
        ListNode* cur2 = new ListNode(0), * dummy = cur2;

        while (cur != nullptr) {
            m_stack.push(cur);
            cur = cur->next;
            if (m_stack.size() == k) {

                while (!m_stack.empty()) {
                    auto item = m_stack.top();
                    auto temp = new ListNode(item->val);
                    cur2->next = temp;
                    cur2 = cur2->next;
                    m_stack.pop();
                    // delete item;
                }
            }
        }

        // tail judge
        while (m_stack.size() > 1) {
            m_stack.pop();
        }
        cur2->next = m_stack.empty() ? nullptr : m_stack.top();

        return dummy->next;
    }

    void test()
    {
        cout << " 25. Reverse nodes in k-group [Hard - 4 - ListNode] " << endl;
        // makeup data
        std::vector<int> data = { 1, 2, 3, 4, 5 };
        int k = 2;
        ListNode* head = fnt::createList(data);
        fnt::printList(head);
        ListNode* res = reverseKGroup(head, k);
        fnt::printList(res);
        // release memory
        // Note: currently we don't have a good way to release memory
        // fnt::freeList(head);  // there is repeated release here, still need to be optimized
        fnt::freeList(res);
    }
};

// RAII Register
struct Solution25Register {
    Solution25Register() {
        Solution s;
        fnt::RegisterSolution("25", [&s]() { s.test(); });
    }
};

static Solution25Register __reg25;