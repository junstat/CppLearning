class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)return 0;
        long lo = 0, hi = x;
        while (lo < hi) {
            long mid = (lo + hi + 1) >> 1;
            if (mid * mid <= x) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};
