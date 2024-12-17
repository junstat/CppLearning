#include <unordered_map>
#include <queue>
#include "../Node.cpp"


class Solution {
public:
    // BFS
    Node *cloneGraph(Node *node) {
        if (node == nullptr) {
            return nullptr;
        }

        queue<Node *> q;
        q.push(node);

        Node *clone = new Node(node->val);
        seen[node] = clone;

        while (!q.empty()) {
            Node *n = q.front();
            q.pop();

            for (Node *neighbor: n->neighbors) {
                if (seen.find(neighbor) == seen.end()) {
                    Node *cloneNeighbor = new Node(neighbor->val);
                    seen[neighbor] = cloneNeighbor;
                    q.push(neighbor);
                }
                seen[n]->neighbors.push_back(seen[neighbor]);
            }
        }
        return clone;
    }

private:
    unordered_map<Node *, Node *> seen;
};