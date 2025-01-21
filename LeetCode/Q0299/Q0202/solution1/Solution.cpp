#include <set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        s.emplace(n);
        for (;;) {
            n = getNext(n);
            if (n == 1) {
                return true;
            } else if (s.count(n)) {
                return false;
            } else {
                s.emplace(n);
            }
        }
    }

    int getNext(int n) {
        int ans = 0;
        while (n) {
            int t = n % 10;
            ans += t * t;
            n /= 10;
        }
        return ans;
    }
};