#include "../../DataStructure/TreeNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return genTrees(1, n);
    }

    vector<TreeNode *> genTrees(int start, int end) {
        vector < TreeNode * > ans;
        if (start > end) {
            ans.push_back(nullptr);
            return ans;
        }

        if (start == end) {
            ans.push_back(new TreeNode(start));
            return ans;
        }

        vector < TreeNode * > left, right;

        for (int i = start; i <= end; ++i) {
            left = genTrees(start, i - 1);
            right = genTrees(i + 1, end);
            for (const auto &lnode: left) {
                for (const auto &rnode: right) {
                    TreeNode *node = new TreeNode(i);
                    node->left = lnode;
                    node->right = rnode;
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
};