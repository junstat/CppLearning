#include "../../DataStructure/ListNode.h"

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        auto dummy = new ListNode(0);       // 头结点
        auto cur = dummy;
        int sum = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            sum = n1 + n2 + sum;
            cur->next = new ListNode(sum % 10);
            sum /= 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (sum) cur->next = new ListNode(sum);
        return dummy->next;
    }
};