#include "ListNode.h"

class Solution {
public:
    // recursion
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;
        head->next = deleteDuplicates(head->next);
        return head->val == head->next->val ? head->next : head;
    }
};