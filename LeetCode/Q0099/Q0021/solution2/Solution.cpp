#include "ListNode.h"

class Solution {
public:
    /*-------------------------------------------------------------------------
     迭代
     ------------------------------------------------------------------------*/
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr || l2 == nullptr) return l1 ? l1 : l2;
        auto head = new ListNode(0);
        auto p = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1 ? l1 : l2;
        return head->next;
    }
};