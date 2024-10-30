#include "Node.h"


class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        if (root->left != nullptr) root->left->next = root->right;
        if (root->right != nullptr && root->next != nullptr) root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
        return root;
    }
};