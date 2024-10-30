#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode *root, int t) {
        findPaths(root, t);
        return paths;
    }

    void findPaths(TreeNode *root, int t) {
        if (root == nullptr) return;
        path.emplace_back(root->val);
        if (root->left == nullptr && root->right == nullptr && t == root->val)
            paths.push_back(path);
        findPaths(root->left, t - root->val);
        findPaths(root->right, t - root->val);
        path.pop_back();

    }

    vector<vector<int>> paths;
    vector<int> path;
};