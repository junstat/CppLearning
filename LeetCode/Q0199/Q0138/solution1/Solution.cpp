#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr) return nullptr;
        unordered_map<Node *, Node *> mp;

        for (auto node = head; node != nullptr; node = node->next)
            mp[node] = new Node(node->val);

        for (auto node = head; node != nullptr; node = node->next) {
            mp[node]->next = mp[node->next];
            mp[node]->random = mp[node->random];

        }
        return mp[head];
    }
};