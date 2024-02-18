#include <vector>
#include <queue>
#include "../../DataStructure/Node.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();

            vector<int> level;
            for (int i = 0; i < n; ++i) {
                auto node = q.front();
                q.pop();
                level.push_back(node->val);
                for (auto child: node->children) {
                    q.push(child);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};