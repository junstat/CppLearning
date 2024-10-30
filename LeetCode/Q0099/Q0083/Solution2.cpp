#include "ListNode.h"

class Solution {
public:
    // iteration
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;
        auto cur = head;
        while (cur->next) {
            if (cur->next->val == cur->val)
                cur->next = cur->next->next;
            else cur = cur->next;
        }
        return head;
    }
};