#include <TreeNode.h>
#include <deque>

using namespace std;

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        dfs(root);
    }

    int next() {
        TreeNode *node = q.back();
        q.pop_back();
        dfs(node->right);
        return node->val;
    }

    bool hasNext() {
        return !q.empty();
    }


private:
    void dfs(TreeNode *root) {
        while (root != nullptr) {
            q.push_back(root);
            root = root->left;
        }
    }

private:
    deque<TreeNode *> q;
};