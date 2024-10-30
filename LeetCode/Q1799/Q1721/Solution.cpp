#include "ListNode.h"

class Solution {
public:
    ListNode *swapNodes(ListNode *head, int k) {
        ListNode *pre, *r, *p = nullptr;
        int len = 1;
        for (p = head; p; p = p->next) {
            if (len == k)
                pre = p;
            len++;
        }
        for (p = head; --len > k; p = p->next);
        r = p;
        swap(pre->val, r->val);
        return head;
    }
};


/*-------------------------------------------------------------------------
 Solution 2: one loop
 ------------------------------------------------------------------------*/
class Solution2 {
public:
    ListNode *swapNodes(ListNode *head, int k) {
        ListNode *pre, *r = nullptr;
        for (auto p = head; p; p = p->next) {
            r = r ? r->next : nullptr;
            if (--k == 0) {
                pre = p;
                r = head;
            }
        }
        swap(pre->val, r->val);
        return head;
    }
};