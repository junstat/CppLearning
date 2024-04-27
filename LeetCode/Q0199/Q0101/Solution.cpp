#include "../../DataStructure/TreeNode.h"

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        return root == nullptr || dfs(root->left, root->right);
    }

    bool dfs(TreeNode *left, TreeNode *right) {
        if (left == nullptr || right == nullptr) return left == right;
        if (left->val != right->val) return false;
        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }
};