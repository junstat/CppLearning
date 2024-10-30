#include "ListNode.h"

class Solution {
public:
    // recursion
    ListNode *reverseKGroup(ListNode *head, int k) {
        auto cur = head;
        int count = 0;
        while (cur != nullptr && count != k) {  // find the k+1 node
            cur = cur->next;
            count++;
        }

        if (count == k) {   // if k+1 node is found
            cur = reverseKGroup(cur, k);   // reverse lis with k+1 node as head
            // head - head-pointer to direct part,
            // cur - head-pointer to reversed part;
            while (count-- > 0) {       // reverse current k-group
                auto temp = head->next;
                head->next = cur;
                cur = head;
                head = temp;
            }
            head = cur;
        }
        return head;
    }
};