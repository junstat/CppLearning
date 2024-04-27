#include <unordered_map>

using namespace std;

class Node {
public:
    int k, v;
    Node *l, *r;

    Node(int k, int v) : k(k), v(v), l(nullptr), r(nullptr) {
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        n = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->r = tail;
        tail->l = head;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            auto node = mp[key];
            refresh(node);
            return node->v;
        }
        return -1;
    }

    void put(int key, int value) {
        Node *node = nullptr;
        if (mp.find(key) != mp.end()) {
            node = mp[key];
            node->v = value;
        } else {
            if (mp.size() == n) {
                auto delNode = tail->l;
                mp.erase(delNode->k);
                del(delNode);
            }
            node = new Node(key, value);
            mp[key] = node;
        }
        refresh(node);
    }

    void refresh(Node *node) {
        del(node);
        node->r = head->r;
        node->l = head;
        head->r->l = node;
        head->r = node;
    }

    void del(Node *node) {
        if (node->l != nullptr) {
            auto left = node->l;
            left->r = node->r;
            node->r->l = left;
        }
    }

    int n;
    Node *head, *tail;
    unordered_map<int, Node *> mp;
};