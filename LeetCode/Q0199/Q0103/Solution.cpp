#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        dfs(root, 0, ans);
        return ans;
    }

    void dfs(TreeNode *cur, int level, vector<vector<int>> &ans) {
        if (!cur) return;
        if (level >= ans.size()) ans.emplace_back();

        vector<int> &vec = ans[level];
        if (level % 2 == 0) {
            vec.push_back(cur->val);
        } else {
            vec.insert(vec.begin(), cur->val);
        }
        dfs(cur->left, level + 1, ans);
        dfs(cur->right, level + 1, ans);
    }
};