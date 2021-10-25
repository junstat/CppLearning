#include <vector>
#include "../../DataStructure/ListNode.h"

class Solution {
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        vector<ListNode *> parts(k, nullptr);
        int len = 0;
        for (auto p = head; p; p = p->next)
            len++;
        int n = len / k, r = len % k;    // n: minimum guaranteed part size; r: extra nodes spread to the first r parts
        ListNode *p = head, *pre = nullptr;
        for (int i = 0; p && i < k; i++, r--) {
            parts[i] = p;
            for (int j = 0; j < n + (r > 0); j++) { // r > 0 means r >0 ? 1 : 0
                pre = p;
                p = p->next;
            }
            pre->next = nullptr;
        }
        return parts;
    }
};