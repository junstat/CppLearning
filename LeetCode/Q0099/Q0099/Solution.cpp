#include "../../DataStructure/TreeNode.h"
#include <algorithm>

using namespace std;

class Solution {
public:
    void recoverTree(TreeNode *root) {
        dfs(root);
        swap(first->val, second->val);
    }

    void dfs(TreeNode *root) {
        if (root == nullptr) return;

        dfs(root->left);

        if (pre != nullptr && root->val < pre->val) {
            if (first == nullptr) first = pre;
            second = root;
        }

        pre = root;
        dfs(root->right);
    }

    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
    TreeNode *pre = nullptr;
};