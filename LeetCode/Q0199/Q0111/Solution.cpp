#include "../../DataStructure/TreeNode.h"
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        int lh = minDepth(root->left), rh = minDepth(root->right);
        return (lh == 0 || rh == 0) ? lh + rh + 1
                                    : 1 + min(lh, rh);
    }
};