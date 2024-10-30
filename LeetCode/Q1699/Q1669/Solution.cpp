#include "ListNode.h"

class Solution {
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
        ListNode *end = list1, *start = nullptr;
        for (int i = 0; i < b; i++, end = end->next)    // locate b upon termination of the loop
            if (i == a - 1) start = end;    // locate the node right before a
        start->next = list2;    // connect the node right before "a" to the head of list2, hence cut off "a" from list1
        while (list2->next)     // traverse till the end of list2
            list2 = list2->next;
        list2->next = end->next;        // connect end of list2 to the node right after b.
        end->next = nullptr;  // cut off b from list1.
        return list1;
    }
};