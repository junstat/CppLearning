#include <vector>
#include "ListNode.h"

class Solution {
public:
    ListNode *mergeNodes(ListNode *head) {
        ListNode *dummy = new ListNode, *r = dummy;
        int pSum = 0;
        for (auto p = head; p != nullptr; p = p->next) {
            if (p->val == 0 && p != head) {
                r->next = new ListNode(pSum);
                r = r->next;
                pSum = 0;
            } else {
                pSum += p->val;
            }
        }
        return dummy->next;
    }
};
