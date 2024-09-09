#include <vector>
#include "ListNode.h"

class Solution {
public:
    ListNode *mergeNodes(ListNode *head) {
        ListNode *dummy = new ListNode, *r = dummy;
        int pSum = 0;
        for (auto p = head; p != nullptr; p = p->next) {
            if (p->val == 0 && p != head) {
                r->next = new ListNode(pSum);
                r = r->next;
                pSum = 0;
            } else {
                pSum += p->val;
            }
        }
        return dummy->next;
    }
};

int main() {
    std::vector<int> source = {0, 3, 1, 0, 4, 5, 2, 0};
    auto head = createList(source);
    fmt::print("source list: ");
    printList(head);
    fmt::print("ans list: ");
    Solution s;
    auto ans = s.mergeNodes(head);
    printList(ans);
}
