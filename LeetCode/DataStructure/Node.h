#ifndef CPPLEARNING_NODE_H
#define CPPLEARNING_NODE_H

#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

#endif //CPPLEARNING_NODE_H
