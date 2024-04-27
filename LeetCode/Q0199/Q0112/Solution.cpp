#include "../../DataStructure/TreeNode.h"

class Solution {
public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root) return false;
        if (root->left == nullptr && root->right == nullptr && root->val == targetSum) return true;
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};