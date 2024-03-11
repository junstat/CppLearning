#include "../../DataStructure/ListNode.h"

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int sum = 0;
        ListNode *dummy = new ListNode(0), *p = dummy;
        while (l1 || l2) {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            sum += a + b;
            p->next = new ListNode(sum % 10);
            sum /= 10;
            p = p->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (sum) p->next = new ListNode(sum);
        return dummy->next;
    }
};