#include "../../DataStructure/TreeNode.h"

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) return nullptr;

        auto left = root->left, right = root->right;
        root->left = invertTree(right);
        root->right = invertTree(left);
        return root;
    }
};