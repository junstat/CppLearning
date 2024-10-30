#include "ListNode.h"

class Solution {
public:
    // recursion
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;

        if (head->val != head->next->val) {
            head->next = deleteDuplicates(head->next);
            return head;
        } else {
            while (head->next && head->val == head->next->val) head = head->next;
            return deleteDuplicates(head->next);
        }
    }
};