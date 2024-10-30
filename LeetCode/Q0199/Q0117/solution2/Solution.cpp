#include "Node.h"

class Solution {
public:
    Node *connect(Node *root) {
        if (root == nullptr) return nullptr;
        if (root->left != nullptr) {
            root->left->next = root->right != nullptr ? root->right : findNex(root->next);
        }
        if (root->right != nullptr) {
            root->right->next = findNex(root->next);
        }
        connect(root->right);
        connect(root->left);
        return root;
    }

    Node *findNex(Node *root) {
        if (root == nullptr) return nullptr;
        if (root->left != nullptr) return root->left;
        if (root->right != nullptr) return root->right;
        return findNex(root->next);
    }
};