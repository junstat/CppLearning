#include "Node.h"

class Solution {
public:
    Node *connect(Node *root) {
        Node *head = root;
        while (head) {
            Node *dummy = new Node(0);
            Node *cur = dummy;
            while (head) {
                if (head->left) {
                    cur->next = head->left;
                    cur = cur->next;
                }
                if (head->right) {
                    cur->next = head->right;
                    cur = cur->next;
                }
                head = head->next;
            }
            head = dummy->next;
        }
        return root;
    }
};