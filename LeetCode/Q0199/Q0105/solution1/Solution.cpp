#include <vector>
#include "../../../DataStructure/TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        PRE = preorder;
        IN = inorder;
        return dfs(0, 0, IN.size() - 1);
    }

    TreeNode *dfs(int ps, int is, int ie) {
        if (ps > PRE.size() - 1 || is > ie) return nullptr;
        TreeNode *root = new TreeNode(PRE[ps]);
        int i;
        for (i = is; i <= ie; ++i) {
            if (IN[i] == root->val) break;
        }
        root->left = dfs(ps + 1, is, i - 1);
        root->right = dfs(ps + i - is + 1, i + 1, ie);
        return root;
    }

    vector<int> PRE;
    vector<int> IN;
};