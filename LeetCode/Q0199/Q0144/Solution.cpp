#include <vector>
#include <TreeNode.h>

using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        dfs(root);
        return ans;
    }

    void dfs(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        ans.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }

private:
    vector<int> ans;
};