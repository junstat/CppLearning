#include <stack>
#include "../../../DataStructure/ListNode.h"

using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        stack<ListNode *> s;
        for (auto p = head; p != nullptr; p = p->next)
            s.push(p);
        for (auto p = head; p != nullptr; p = p->next) {
            auto q = s.top();
            if (q->val != p->val) return false;
            s.pop();
        }
        return true;
    }
};