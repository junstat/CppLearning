#include <cmath>

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int a = 0, b = static_cast<int>(sqrt(c)); a <= b;) {
            if (a * a == c - b * b) {
                return true;
            } else if (a * a < c - b * b) {
                ++a;
            } else {
                --b;
            }
        }
        return false;
    }
};