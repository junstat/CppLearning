#include <vector>
#include "ListNode.h"

class Solution {
public:
    vector<int> nextLargerNodes(ListNode *head) {
        vector<int> res, stack;
        for (auto p = head; p; p = p->next) {
            while (!stack.empty() && res[stack.back()] < p->val) {
                res[stack.back()] = p->val;
                stack.pop_back();
            }
            stack.push_back(res.size());
            res.push_back(p->val);
        }
        for (int i: stack) res[i] = 0;
        return res;
    }
};