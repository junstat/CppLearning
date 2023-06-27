#include "../../DataStructure/ListNode.h"

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        auto dummy = new ListNode(0, head);
        auto pre = dummy;
        while (pre->next != nullptr) {
            if (pre->next->val == val)
                pre->next = pre->next->next;
            else
                pre = pre->next;
        }
        return dummy->next;
    }
};