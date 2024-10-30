#include <vector>
#include "ListNode.h"

class Solution {
public:
    int numComponents(ListNode *head, vector<int> &nums) {
        int len = 0;
        for (auto p = head; p; p = p->next)
            len++;
        vector<bool> exits(len, false);
        for (int num: nums)         // num in nums
            exits[num] = true;
        int count = 0;
        while (head) {
            if (exits[head->val] &&
                (head->next == nullptr || !exits[head->next->val]))
                count++;
            head = head->next;
        }
        return count;
    }
};