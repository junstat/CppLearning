#include <unordered_map>
#include <list>

using namespace std;

// 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
// put 使用STL list API 超过O(1)
class LRUCache {
public:
    explicit LRUCache(int capacity) : n(capacity) {
    }

    int get(int key) {
        if (seen.find(key) == seen.end()) {
            return -1;
        }
        order.remove(key);
        order.push_front(key);
        return seen[key];
    }

    void put(int key, int value) {
        if (seen.find(key) != seen.end()) {
            order.remove(key);
        } else if (seen.size() == n) {
            seen.erase(order.back());
            order.pop_back();
        }
        seen[key] = value;
        order.push_front(key);
    }

private:
    int n;
    unordered_map<int, int> seen;
    list<int> order;
};