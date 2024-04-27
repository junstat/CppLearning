#include <vector>

using namespace std;

class MyHashSet {
public:
    MyHashSet() {
        nodes.resize(1000009, false);
    }

    void add(int key) {
        nodes[key] = true;
    }

    void remove(int key) {
        nodes[key] = false;
    }

    bool contains(int key) {
        return nodes[key];
    }

    vector<bool> nodes;
};