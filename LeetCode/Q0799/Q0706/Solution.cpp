#include <vector>

using namespace std;

class MyHashMap {
public:
    MyHashMap() {
        data.resize(1e6 + 9, -1);
    }

    void put(int key, int value) {
        data[key] = value;
    }

    int get(int key) {
        return data[key];
    }

    void remove(int key) {
        data[key] = -1;
    }

private:
    vector<int> data;
};