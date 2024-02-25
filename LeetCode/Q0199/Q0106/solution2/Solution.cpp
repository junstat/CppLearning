#include <vector>
#include "../../../DataStructure/TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        in = inorder.size() - 1;
        post = postorder.size() - 1;
        return dfs(postorder, inorder, nullptr);
    }

    TreeNode *dfs(vector<int> &postorder, vector<int> &inorder, TreeNode *end) {
        if (post < 0) return nullptr;
        TreeNode *root = new TreeNode(postorder[post--]);

        // if right node exist, create right subtree
        if (inorder[in] != root->val)
            root->right = dfs(postorder, inorder, root);
        in--;

        // if left node exist, create left subtree
        if ((end == nullptr) || (inorder[in] != end->val))
            root->left = dfs(postorder, inorder, end);
        return root;
    }

private:
    int in = 0;
    int post = 0;
};