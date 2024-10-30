#include "ListNode.h"

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        auto fast = head;
        auto slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};