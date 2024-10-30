#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder) {
        auto root = new TreeNode(preorder[preIndex++]);
        if (root->val != postorder[posIndex])
            root->left = constructFromPrePost(preorder, postorder);
        if (root->val != postorder[posIndex])
            root->right = constructFromPrePost(preorder, postorder);
        posIndex++;
        return root;
    }

    int preIndex = 0, posIndex = 0;
};