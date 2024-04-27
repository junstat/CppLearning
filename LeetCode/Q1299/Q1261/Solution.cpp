#include <set>
#include "../../DataStructure/TreeNode.h"

using namespace std;

class FindElements {
public:
    FindElements(TreeNode *root) {
        root->val = 0;
        nums.insert(0);
        dfs(root);
    }

    bool find(int target) {
        return nums.find(target) != nums.end();
    }

    void dfs(TreeNode *root) {
        if (root == nullptr) return;
        if (root->left) {
            root->left->val = 2 * root->val + 1;
            nums.insert(2 * root->val + 1);
            dfs(root->left);
        }
        if (root->right) {
            root->right->val = 2 * root->val + 2;
            nums.insert(2 * root->val + 2);
            dfs(root->right);
        }
    }

    set<int> nums;
};