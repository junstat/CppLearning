#include "TreeNode.h"

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return validate(root);
    }

    bool validate(TreeNode *node) {
        if (node == nullptr) return true;
        if (!validate(node->left)) return false;
        if (pre != nullptr && pre->val >= node->val)
            return false;
        pre = node;
        return validate(node->right);
    }

    TreeNode *pre = nullptr;
};