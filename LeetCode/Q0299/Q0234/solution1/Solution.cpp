#include "ListNode.h"

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        auto slow = head, fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // if fast != nullptr, list had odd numbers
        if (fast != nullptr) slow = slow->next;
        slow = reverseList(slow);
        while (slow != nullptr) {
            if (slow->val != head->val) return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }

    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *pre, *p = head, *r = p->next;
        p->next = nullptr;
        while (r != nullptr) {
            pre = p;
            p = r;
            r = r->next;
            p->next = pre;
        }
        return p;
    }
};