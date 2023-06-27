#include "../../DataStructure/ListNode.h"

class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        if (head == nullptr) return head;

        auto evenHead = new ListNode(0);
        auto oddHead = new ListNode(0);
        auto even = evenHead;
        auto odd = oddHead;
        int count = 0;
        while (head != nullptr) {
            count ++;
            if (count% 2 == 0) {
                even->next = head;
                even = even->next;
            } else {
                odd->next = head;
                odd = odd->next;
            }
            head = head->next;
        }
        even->next = nullptr;
        odd->next = evenHead->next;
        return oddHead->next;
    }
};