#include <vector>
#include "../../DataStructure/TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return dfs(nums, 0, nums.size() - 1);
    }

    TreeNode *dfs(const vector<int> &nums, int l, int r) {
        if (l > r) return nullptr;
        int mid = (l + r + 1) / 2;

        auto root = new TreeNode(nums[mid]);
        root->left = dfs(nums, l, mid - 1);
        root->right = dfs(nums, mid + 1, r);
        return root;
    }
};