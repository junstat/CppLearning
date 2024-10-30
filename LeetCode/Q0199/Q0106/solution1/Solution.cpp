#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        IN = inorder;
        POST = postorder;
        if (IN.size() != POST.size()) return nullptr;
        return dfs(0, IN.size() - 1, POST.size() - 1);
    }

    TreeNode *dfs(int is, int ie, int rii) {
        if (is > ie) return nullptr;
        TreeNode *root = new TreeNode(POST[rii]);
        int i = 0;
        while (POST[rii] != IN[ie - i]) i++;

        root->left = dfs(is, ie - i - 1, rii - i - 1);
        root->right = dfs(ie - i + 1, ie, rii - 1);
        return root;
    }

    vector<int> IN;
    vector<int> POST;
};