
#include "ListNode.h"

class Solution {
public:
    ListNode *deleteNodes(ListNode *head, int m, int n) {
        auto dummy = new ListNode(0, head);
        auto *p = dummy;
        int cnt = 0;
        while (p) {
            if (cnt != 0 && cnt % m == 0) {
                for (int i = 0; i < n && p->next; i++)
                    p->next = p->next->next;
            }
            cnt++;
            p = p->next;
        }
        return dummy->next;
    }
};