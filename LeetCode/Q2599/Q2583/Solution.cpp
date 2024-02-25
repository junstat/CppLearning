#include <vector>
#include <queue>
#include <algorithm>
#include "../../DataStructure/TreeNode.h"

using namespace std;

class Solution {
public:
    using ll = long long;

    long long kthLargestLevelSum(TreeNode *root, int k) {
        queue<TreeNode *> q;
        if (!root) return -1;
        q.push(root);
        vector<ll> nums;
        while (!q.empty()) {
            int n = q.size();
            ll sum = 0;
            for (int i = 0; i < n; ++i) {
                auto x = q.front();
                q.pop();
                sum += x->val;
                if (x->left) q.push(x->left);
                if (x->right) q.push(x->right);
            }
            nums.push_back(sum);
        }
        if (nums.size() < k) return -1;
        sort(nums.begin(), nums.end(), greater<>());
        return nums[k - 1];
    }
};