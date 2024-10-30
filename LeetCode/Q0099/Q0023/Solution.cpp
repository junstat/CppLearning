#include <vector>
#include <queue>
#include "ListNode.h"

using namespace std;

struct LessThanNode {
    bool operator()(const ListNode *lhs, const ListNode *rhs) {
        return lhs->val > rhs->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        auto dummy = new ListNode(0);
        auto cur = dummy;
        priority_queue<ListNode *, vector<ListNode *>, LessThanNode> q;
        for (ListNode *&node : lists)
            if (node) q.push(node);

        while (!q.empty()) {
            cur->next = q.top();
            q.pop();
            cur = cur->next;
            if (cur->next) q.push(cur->next);
        }
        return dummy->next;
    }
};