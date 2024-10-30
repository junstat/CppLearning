#include "Node.h"

class Solution {
public:
    Node* connect(Node* root) {
        Node* prev = root, *cur = nullptr;
        while (prev) {
            cur = prev;
            while (cur != nullptr && cur->left != nullptr) {
                cur->left->next = cur->right;
                if (cur->next != nullptr) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            prev = prev->left;
        }
        return root;
    }
};