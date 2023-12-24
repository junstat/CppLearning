#include "../../../DataStructure/ListNode.h"

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return head;
        int len = 1;
        auto tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        k %= len;
        if (k == 0) return head;

        auto pre = head;
        while (--len > k) pre = pre->next;  // 找到倒数第k个结点的前驱
        auto newHead = pre->next;
        tail->next = head;
        pre->next = nullptr;
        return newHead;
    }
};