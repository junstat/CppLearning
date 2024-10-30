#include "ListNode.h"


class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        auto slow = head, fast = head, pre = head;
        while (fast != nullptr && fast->next != nullptr) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        return merge(sortList(head), sortList(slow));
    }

    ListNode *merge(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr || l2 == nullptr) return l1 == nullptr ? l2 : l1;
        if (l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};