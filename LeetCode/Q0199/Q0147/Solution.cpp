#include "ListNode.h"

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        auto dummy = new ListNode(0, head);

        auto p = dummy->next;
        auto r = p->next;
        p->next = nullptr;
        p = r;

        while (p != nullptr) {
            r = p->next;
            auto pre = dummy;
            while (pre->next != nullptr && pre->next->val < p->val)
                pre = pre->next;
            p->next = pre->next;
            pre->next = p;
            p = r;
        }
        return dummy->next;
    }
};