#include "../../DataStructure/ListNode.h"

class Solution {
public:
    ListNode *plusOne(ListNode *head) {
        // Sentinel head
        auto dummy = new ListNode(0, head);
        auto notNine = dummy;

        // find the rightmost not-nine digit
        while (head != nullptr) {
            if (head->val != 9) notNine = head;
            head = head->next;
        }

        // increase this rightmost not-nine digit by 1
        notNine->val++;
        notNine = notNine->next;

        // set all the following nines to zeros
        while (notNine != nullptr) {
            notNine->val = 0;
            notNine = notNine->next;
        }

        return dummy->val != 0 ? dummy : dummy->next;
    }
};