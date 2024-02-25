#include <vector>
#include "../../DataStructure/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries) {
        vector<vector<int>> ans;
        traverse(root);
        for (int q: queries) {
            auto it = lower_bound(v.begin(), v.end(), q);
            if (it != v.end() && *it == q)
                ans.push_back({q, q});
            else
                ans.push_back({it == v.begin() ?-1:*prev(it), it == v.end() ?-1: *it});
        }
        return ans;
    }

    void traverse(TreeNode *n) {
        if (n != nullptr) {
            traverse(n->left);
            if (v.empty() || v.back() < n->val)
                v.push_back(n->val);
            traverse(n->right);
        }
    }

    vector<int> v;
};