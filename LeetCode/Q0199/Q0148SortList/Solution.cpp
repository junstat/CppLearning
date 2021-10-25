#include "../../DataStructure/ListNode.h"


/*-------------------------------------------------------------------------
 this problem can be easily solved using recurrence and divide-and-conquer.
 But it consumes program stack to store the recurring function stack frame,
 actually it consumes o(lgn) space complexity. Recursion use up-to-bottom
 strategy , why not try the opposite way--bottom-to-up, luckily it works,
 it only consumes 0(1) space complexity and o(nlgn) time complexity.
 ------------------------------------------------------------------------*/

/**
 * Merge sort use bottom-up policy,
 * so Space Complexity is O(1)
 * Time Complexity is O(NlgN)
 * stable sort
*/
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        // get the linked list's length
        auto cur = head;
        int length = 0;
        while (cur != nullptr) {
            length++;
            cur = cur->next;
        }

        auto dummy = new ListNode(0, head);
        ListNode *left, *right, *tail;
        for (int step = 1; step < length; step <<= 1) {
            cur = dummy->next;
            tail = dummy;
            while (cur) {
                left = cur;
                right = split(left, step);
                cur = split(right, step);
                tail = merge(left, right, tail);
            }
        }
        return dummy->next;
    }

private:
    /**
     * Divide the linked list into two lists,
     * while the first list contains first n ndoes
     * return the second list's head
     */
    ListNode *split(ListNode *head, int n) {
        for (int i = 1; head && i < n; i++) head = head->next;

        if (!head) return nullptr;
        ListNode *second = head->next;
        head->next = nullptr;
        return second;
    }

    /**
      * merge the two sorted linked list l1 and l2,
      * then append the merged sorted linked list to the node head
      * return the tail of the merged sorted linked list
      */
    ListNode *merge(ListNode *l1, ListNode *l2, ListNode *head) {
        auto cur = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
        }
        cur->next = (l1 ? l1 : l2);
        while (cur->next) cur = cur->next;
        return cur;
    }
};