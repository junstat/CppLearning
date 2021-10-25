#include "../../DataStructure/ListNode.h"
#include "../../DataStructure/TreeNode.h"

/*-------------------------------------------------------------------------
 Solution 1: Brute DFS
 Time O(N * min(L, H))
 Space O(H)
 where N = tree size, H = tree height, L = list length
 ------------------------------------------------------------------------*/
class Solution {
public:
    bool isSubPath(ListNode *head, TreeNode *root) {
        if (!head) return true;
        if (!root) return false;
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }

    bool dfs(ListNode *head, TreeNode *root) {
        if (!head) return true;
        if (!root) return false;
        return head->val == root->val && (dfs(head->next, root->left) || dfs(head->next, root->right));
    }
};