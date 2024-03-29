#include <cstdlib>

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) x = 1 / x;
        long num = labs(n);
        double ans = 1;
        while (num) {
            if ((num & 1) == 1) ans = ans * x;
            x = x * x;
            num >>= 1;
        }
        return ans;
    }
};