#include "../../DataStructure/ListNode.h"

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if (head == nullptr) return head;
        auto dummy = new ListNode(0, head);
        auto pre = dummy;

        for (int i = 0; i < left - 1; i++) pre = pre->next;

        auto start = pre->next;
        auto then = start->next;

        for (int i = 0; i < right - left; i++) {
            start->next = then->next;       // 防断链
            then->next = pre->next;         // 把then插入
            pre->next = then;               // pre与start之间
            then = start->next;
        }
        return dummy->next;
    }
};