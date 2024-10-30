#include "ListNode.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        auto pA = headA, pB = headB;
        while (pA != pB) {
            pA = pA != nullptr ? pA->next : headB;
            pB = pB != nullptr ? pB->next : headA;
        }
        return pA;
    }
};