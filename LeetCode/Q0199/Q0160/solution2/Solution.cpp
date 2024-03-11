#include "../../../DataStructure/ListNode.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = getLength(headA), n = getLength(headB);
        if (m < n)
            return getIntersectionNode(headB, headA);
        auto p = headA, q = headB;
        for (int i = 0; i < m - n; i++)
            p = p->next;
        while (p != q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }

private:
    int getLength(ListNode *head) {
        if (head == nullptr) return 0;
        int length = 1;
        auto p = head;
        while (p) {
            p = p->next;
            length++;
        }
        return length;
    }
};