#include <vector>
#include "../../DataStructure/Node.h"

using namespace std;

class Solution {
public:
    vector<int> preorder(Node *root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }

    void dfs(Node *root, vector<int> &ans) {
        if (!root)return;
        ans.push_back(root->val);
        for (auto &child: root->children) {
            dfs(child, ans);
        }
    }
};