#include <vector>
#include <tuple>
#include <algorithm>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        vector<tuple<int, int, int >> nodes;
        dfs(root, 0, 0, nodes);
        sort(nodes.begin(), nodes.end());
        vector<vector<int>> ans;
        int lastCol = INT_MIN;
        for (const auto &[col, row, value]: nodes) {
            if (col != lastCol) {
                lastCol = col;
                ans.emplace_back();
            }
            ans.back().push_back(value);
        }
        return ans;
    }

    void dfs(TreeNode *root, int x, int y, vector<tuple<int, int, int >> &nodes) {
        if (root == nullptr) return;
        nodes.emplace_back(x, y, root->val);
        dfs(root->left, x - 1, y + 1, nodes);
        dfs(root->right, x + 1, y + 1, nodes);
    }
};