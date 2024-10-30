#include <iostream>
#include <queue>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    bool isCousins(TreeNode *root, int x, int y) {
        if (!root)return false;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            bool findX = false, findY = false;
            for (int i = 0; i < size; ++i) {
                TreeNode *cur = q.front();
                q.pop();
                if (cur->val == x) findX = true;
                if (cur->val == y) findY = true;
                if (cur->left && cur->right) {
                    if (cur->left->val == x && cur->right->val == y) return false;
                    if (cur->left->val == y && cur->right->val == x)return false;
                }
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            if (findX && findY) return true;
        }
        return false;
    }
};