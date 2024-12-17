#include "../Node.cpp"
#include <unordered_map>

using namespace std;

class Solution {
public:
    // DFS
    Node *cloneGraph(Node *node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (m.find(node->val) != m.end()) {
            return m[node->val];
        }
        Node *cloned = new Node(node->val);
        m[node->val] = cloned;
        for (auto neighbor: node->neighbors) {
            cloned->neighbors.push_back(cloneGraph(neighbor));
        }
        return cloned;
    }

private:
    unordered_map<int, Node *> m;
};