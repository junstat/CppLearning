#include "../../DataStructure/TreeNode.h"

class Solution {
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        dfs(cloned, target->val);
        return ans;
    }

    void dfs(TreeNode *root, const int &val) {
        if (root == nullptr) return;
        if (root->val == val) ans = root;
        dfs(root->left, val);
        dfs(root->right, val);
    }

    TreeNode *ans;
};