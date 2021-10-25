#include "../../DataStructure/ListNode.h"

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr) return head;
        ListNode *pre, *p = head, *r = p->next;
        p->next = nullptr;
        while (r) {
            pre = p;
            p = r;
            r = r->next;
            p->next = pre;
        }
        head = p;
        return head;
    }
};