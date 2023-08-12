#include "../../DataStructure/ListNode.h"
#include "../../DataStructure/TreeNode.h"

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == nullptr) return nullptr;
        return toBST(head, nullptr);
    }

    TreeNode *toBST(ListNode *head, ListNode *tail) {
        if (head == tail) return nullptr;

        auto slow = head;
        auto fast = head;

        while (fast != tail && fast->next != tail) {    // 找中点
            fast = fast->next->next;
            slow = slow->next;
        }
        auto root = new TreeNode(slow->val);
        root->left = toBST(head, slow);
        root->right = toBST(slow->next, tail);
        return root;
    }
};