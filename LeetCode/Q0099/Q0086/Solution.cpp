#include "ListNode.h"

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode left(0), right(0);
        auto l = &left, r = &right;

        while (head) {
            ListNode *&ref = head->val < x ? l : r;
            ref->next = head;
            ref = ref->next;
            head = head->next;
        }
        l->next = right.next;
        r->next = nullptr;
        return left.next;
    }
};