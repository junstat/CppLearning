#include "TreeNode.h"
#include <vector>
#include <map>
#include <queue>

using namespace std;


class Solution {
public:
    using pq = priority_queue<vector<int>, vector<vector<int>>, greater<>>;
    pq q;

    vector<vector<int>> verticalTraversal(TreeNode *root) {
        vector<int> info = {0, 0, root->val};
        q.push(info);
        dfs(root, info);
        vector<vector<int>> ans;
        while (!q.empty()) {
            vector<int> col;
            auto top = q.top();
            while (!q.empty() && q.top()[0] == top[0]) {
                col.push_back(q.top()[2]);
                q.pop();
            }
            ans.push_back(col);
        }
        return ans;
    }

    void dfs(TreeNode *root, const vector<int> &fa) {
        if (root->left) {
            vector<int> info = {fa[0] - 1, fa[1] + 1, root->left->val};
            q.push(info);
            dfs(root->left, info);
        }
        if (root->right) {
            vector<int> info = {fa[0] + 1, fa[1] + 1, root->right->val};
            q.push(info);
            dfs(root->right, info);
        }
    }
};
