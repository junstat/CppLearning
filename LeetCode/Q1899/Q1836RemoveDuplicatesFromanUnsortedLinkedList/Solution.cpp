#include <unordered_map>
#include <vector>
#include "ListNode.h"

class Solution {
public:
    ListNode *deleteDuplicatesUnsorted(ListNode *head) {
        unordered_map<int, int> frequency;
        for (auto p = head; p; p = p->next) frequency[p->val]++;

        auto dummy = new ListNode(0, head);
        auto rear = dummy;
        for (auto p = head; p; p = p->next) {
            if (frequency[p->val] > 1)
                rear->next = p->next;
            else
                rear = p;
        }
        return dummy->next;
    }
};

ListNode *createList(vector<int> &nums) {
    auto dummy = new ListNode(0);
    ListNode *p;
    int i;
    for (p = dummy, i = 0; i < nums.size(); i++, p = p->next)
        p->next = new ListNode(nums[i]);
    return dummy->next;
}

ostream &operator<<(ostream &out, ListNode *head) {
    if (!head) out << "list is empty.....";
    for (auto p = head; p; p = p->next)
        out << p->val << " ";
    out << endl;
    return out;
}

int main() {
//    vector<int> nums = {1, 2, 3, 2};
//    vector<int> nums = {1, 2, 1, 2};
    vector<int> nums = {3, 2, 2, 1, 3, 2, 4};
    auto head = createList(nums);
    cout << head;
    auto s = new Solution();
    auto res = s->deleteDuplicatesUnsorted(head);
    cout << res << endl;

}