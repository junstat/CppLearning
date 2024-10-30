#include "ListNode.h"

class Solution {
public:
    // iteration
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return head;

        // to guarantee the dummy node is not same as the original head.
        auto dummy = new ListNode(0 == head->val ? 1 : 0, head);

        auto pre = dummy;
        auto cur = head;
        auto first = dummy; // the first node in the new unduplicated(result) list.

        while (cur && cur->next) {
            // we found a unique node, we connect it at the tail of the unduplicated list,
            // and update the first node.
            if (cur->val != pre->val && cur->val != cur->next->val) {
                first->next = cur;
                first = first->next;
            }
            pre = cur;
            cur = cur->next;
        }

        if (pre->val != cur->val) { // the last node needs to be dealt with independently
            first->next = cur;
            first = first->next;
        }

        first->next = nullptr;  // the subsequent list is duplicate.
        return dummy->next;
    }
};