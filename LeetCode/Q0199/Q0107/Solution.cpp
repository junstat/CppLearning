#include <vector>
#include <queue>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.insert(ans.begin(), level);
        }
        return ans;
    }
};