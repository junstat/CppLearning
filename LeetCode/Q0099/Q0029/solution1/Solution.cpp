#include <climits>

class Solution {
public:
    const static int MIN = INT_MIN, MAX = INT_MAX, LIMIT = MIN / 2;

    int divide(int a, int b) {
        if (a == MIN && b == -1) return MAX;
        bool negative = (a > 0 && b < 0) || (a < 0 && b > 0);
        if (a > 0) a = -a;
        if (b > 0) b = -b;
        int ans = 0;
        while (a <= b) { // a,b都被映射到了负数，a <= b 即绝对值 a >= b
            int c = b, d = -1;
            while (c >= LIMIT && d >= LIMIT && c >= a - c) {
                c += c;
                d += d;
            }
            a -= c;
            ans += d;
        }
        return negative ? ans : -ans;
    }
};