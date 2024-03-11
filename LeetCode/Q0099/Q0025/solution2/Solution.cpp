#include "../../../DataStructure/ListNode.h"

class Solution {
public:
    // iteration
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr || k == 1) return head;
        auto dummy = new ListNode(0, head);
        int len = 1;
        while (head->next) {        // 求链表长
            head = head->next;
            len++;
        }

        auto pre = dummy;
        for (int l = 0; l + k <= len; l += k) {     // 按k个元素给链表分组
            auto cur = pre->next;
            auto suc = cur->next;
            for (int i = 1; i < k; i++) {
                cur->next = suc->next;
                suc->next = pre->next;
                pre->next = suc;
                suc = cur->next;
            }
            pre = cur;
        }
        return dummy->next;
    }
};