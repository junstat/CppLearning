#include "../../DataStructure/TreeNode.h"

class Solution {
public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        if (root == nullptr) {
            return false;
        }
        if (isSameTree(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode *root, TreeNode *subRoot) {
        if (root == nullptr && subRoot == nullptr) {
            return true;
        }
        if (root == nullptr || subRoot == nullptr) {
            return false;
        }
        if (root->val != subRoot->val) {
            return false;
        }
        return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
    }
};