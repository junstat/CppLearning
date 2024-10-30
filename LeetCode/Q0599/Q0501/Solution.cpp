#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    void inOrder(TreeNode *root, TreeNode *&pre, int &cur, int &max, vector<int> &ans) {
        if (!root) return;
        inOrder(root->left, pre, cur, max, ans);
        if (pre)
            cur = (root->val == pre->val) ? cur + 1 : 1;
        if (cur == max)
            ans.push_back(root->val);
        else if (cur > max) {
            ans.clear();
            ans.push_back(root->val);
            max = cur;
        }
        pre = root;
        inOrder(root->right, pre, cur, max, ans);
    };

    vector<int> findMode(TreeNode *root) {
        vector<int> ans;
        if (!root) return ans;
        TreeNode *pre = nullptr;
        int cur = 1, max = 0;
        inOrder(root, pre, cur, max, ans);
        return ans;
    }
};