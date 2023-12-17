#include <vector>

using namespace std;

struct ListNode {
    int index, value, count;
    ListNode *next;

    ListNode(int index, int value, ListNode *next) : index(index), value(value), count(0), next(next) {}
};


class Solution {
public:
    vector<int> secondGreaterElement(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        auto head = new ListNode(0, 0, nullptr);
        for (int i = 0; i < n; ++i) {
            ListNode *prev = head, *cur = head->next;
            while (cur != nullptr && cur->value < nums[i]) {
                cur->count += 1;
                if (cur->count > 1) {
                    ans[cur->index] = nums[i];
                    prev->next = cur->next;
                } else {
                    prev = cur;
                }
                cur = cur->next;
            }
            prev->next = new ListNode(i, nums[i], cur);
        }
        return ans;
    }
};
