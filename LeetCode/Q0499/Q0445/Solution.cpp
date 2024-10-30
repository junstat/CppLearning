#include <stack>
#include "ListNode.h"

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        stack<int> s1;
        stack<int> s2;

        for (auto p = l1; p; p = p->next)
            s1.push(p->val);

        for (auto p = l2; p; p = p->next)
            s2.push(p->val);

        int sum = 0;
        ListNode *head = nullptr;
        while (!s1.empty() || !s2.empty() || sum != 0) {
            int n1 = s1.empty() ? 0 : s1.top();
            int n2 = s2.empty() ? 0 : s2.top();
            sum = n1 + n2 + sum;
            auto newNode = new ListNode(sum % 10);
            newNode->next = head;
            head = newNode;
            sum /= 10;
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();
        }
        return head;
    }
};