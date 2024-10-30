#include <vector>
#include "Node.h"

using namespace std;

class Solution {
public:
    vector<int> postorder(Node *root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }

    void dfs(Node *const root, vector<int> &ans) {
        if (!root) return;
        for (auto node: root->children) {
            dfs(node, ans);
        }
        ans.push_back(root->val);
    }
};