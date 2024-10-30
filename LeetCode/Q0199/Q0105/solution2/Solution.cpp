#include <vector>
#include <climits>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return dfs(preorder, inorder, INT_MIN);
    }

    TreeNode *dfs(vector<int> &preorder, vector<int> &inorder, int stop) {
        if (pre >= preorder.size()) return nullptr;
        if (inorder[in] == stop) {
            in++;
            return nullptr;
        }
        auto *root = new TreeNode(preorder[pre++]);
        root->left = dfs(preorder, inorder, root->val);
        root->right = dfs(preorder, inorder, stop);
        return root;
    }

    int in = 0;
    int pre = 0;
};