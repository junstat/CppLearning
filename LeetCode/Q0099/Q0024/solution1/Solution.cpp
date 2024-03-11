#include "../../../DataStructure/ListNode.h"

class Solution {
public:
    // recursion
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        auto suc = head->next;
        head->next = swapPairs(suc->next);
        suc->next = head;
        return suc;
    }
};