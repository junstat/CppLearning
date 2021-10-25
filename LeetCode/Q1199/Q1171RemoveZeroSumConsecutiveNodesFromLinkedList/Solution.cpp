#include <unordered_map>
#include "../../DataStructure/ListNode.h"

class Solution {
public:
    ListNode *removeZeroSumSublists(ListNode *head) {
        auto dummy = new ListNode(0, head);
        int accumulated = 0;
        unordered_map<int, ListNode *> seen;
        for (auto p = dummy; p; p = p->next)
            seen[accumulated += p->val] = p;
        accumulated = 0;
        for (auto p = dummy; p; p = p->next)
            p->next = seen[accumulated += p->val]->next;
        return dummy->next;
    }
};