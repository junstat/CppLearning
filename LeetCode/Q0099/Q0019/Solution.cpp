#include "../../DataStructure/ListNode.h"

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        auto dummy = new ListNode(0, head);
        auto fast = dummy->next;
        auto slow = dummy;
        // fast 先走n步
        for (int i = 0; i < n; i++) fast = fast->next;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;  // 删除倒数第n个结点
        return dummy->next;
    }
};