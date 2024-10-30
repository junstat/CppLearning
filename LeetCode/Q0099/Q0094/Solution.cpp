#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }

    void dfs(TreeNode *root, vector<int> &ans) {
        if (root) {
            dfs(root->left, ans);
            ans.push_back(root->val);
            dfs(root->right, ans);
        }
    }
};