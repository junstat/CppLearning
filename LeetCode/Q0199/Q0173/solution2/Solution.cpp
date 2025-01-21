#include <TreeNode.h>
#include <deque>

using namespace std;

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        cur = root;
    }

    int next() {
        while (cur != nullptr) {
            stack.push_back(cur);
            cur = cur->left;
        }
        cur = stack.back();
        stack.pop_back();
        int ans = cur->val;
        cur = cur->right;
        return ans;
    }

    bool hasNext() {
        return cur != nullptr || !stack.empty();
    }

private:
    deque<TreeNode *> stack;
    TreeNode *cur;
};