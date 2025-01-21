#include <vector>
#include <TreeNode.h>

using namespace std;

class Solution {
public:
    vector<int> ans;

    vector<int> rightSideView(TreeNode *root) {
        rightSideView(root, 0);
        return ans;
    }

    void rightSideView(TreeNode *root, int depth) {
        if (root == nullptr) {
            return;
        }
        if (ans.size() == depth) {
            ans.push_back(root->val);
        }
        rightSideView(root->right, depth + 1);
        rightSideView(root->left, depth + 1);
    }
};