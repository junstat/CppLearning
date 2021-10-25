#include "../../DataStructure/ListNode.h"

class Solution {
public:
    ListNode *middleNode(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        auto slow = head;
        auto fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};