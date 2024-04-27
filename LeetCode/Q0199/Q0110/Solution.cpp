#include <algorithm>
#include "../../DataStructure/TreeNode.h"

using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        return abs(depth(root->left) - depth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    int depth(TreeNode *root) {
        return !root ? 0 : max(depth(root->left), depth(root->right)) + 1;
    }
};