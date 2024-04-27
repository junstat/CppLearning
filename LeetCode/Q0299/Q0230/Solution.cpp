#include "../../DataStructure/TreeNode.h"
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        priority_queue<int, vector<int>, less<>> pq;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (pq.size() < k) pq.push(node->val);
            else if (pq.top() > node->val) {
                pq.pop();
                pq.push(node->val);
            }
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
        return pq.top();
    }
};