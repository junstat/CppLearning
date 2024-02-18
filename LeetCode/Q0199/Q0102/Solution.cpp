#include <vector>
#include <queue>
#include "../../DataStructure/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> t;
            for (int i = 0; i < n; ++i) {
                auto node = q.front();
                q.pop();
                t.push_back(node->val);
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            ans.push_back(t);
        }
        return ans;
    }
};