#include "../../../DataStructure/ListNode.h"

class Solution {
public:
    // iteration
    // 后继: successor
    // pre->cur->suc->rear ==> pre->suc->cur->rear
    ListNode *swapPairs(ListNode *head) {
        auto dummy = new ListNode(0, head), pre = dummy;
        while (pre->next && pre->next->next) {
            auto cur = pre->next, suc = cur->next, rear = suc->next;
            pre->next = suc;
            suc->next = cur;
            cur->next = rear;
            pre = cur;
        }
        return dummy->next;
    }
};