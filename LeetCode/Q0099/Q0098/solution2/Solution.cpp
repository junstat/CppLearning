#include "TreeNode.h"
#include <stack>

using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (root == nullptr) return true;
        stack<TreeNode *> stk;
        TreeNode *pre = nullptr;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (pre != nullptr && root->val <= pre->val)
                return false;
            pre = root;
            root = root->right;
        }
        return true;
    }
};