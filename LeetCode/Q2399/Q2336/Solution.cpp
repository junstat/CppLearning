#include <set>

using namespace std;

class SmallestInfiniteSet {
public:
    int cur;
    set<int> s;

    SmallestInfiniteSet() {
        cur = 1;
    }

    int popSmallest() {
        if (s.size()) {
            int ans = *s.begin();
            s.erase(ans);
            return ans;
        } else {
            return cur++;
        }
    }

    void addBack(int num) {
        if (cur > num)
            s.insert(num);
    }
};