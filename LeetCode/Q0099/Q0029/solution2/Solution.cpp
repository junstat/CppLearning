#include <climits>

using namespace std;

class Solution {
public:
    const static int MIN = INT_MIN, MAX = INT_MAX, LIMIT = MIN / 2;

    int divide(int a, int b) {
        long x = a, y = b;
        bool isNeg = (x < 0 && y > 0) || (x > 0 && y < 0);
        if (x < 0) x = -x;
        if (y < 0) y = -y;
        long l = 0, r = x;
        while (l < r) {
            long mid = (l + r + 1) >> 1;
            if (mul(mid, y) <= x) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        long ans = isNeg ? -l : l;
        if (ans > MAX || ans < MIN)return MAX;
        return (int) ans;
    }

    long mul(long a, long b) {
        long ans = 0;
        while (b > 0) {
            if (b & 1)ans += a;
            b >>= 1;
            a <<= 1;
        }
        return ans;
    }
};