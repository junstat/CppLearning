class Solution {
public:
    int climbStairs(int n) {
        long a = 1, b = 1;
        while (n-- > 0) a = (b += a) - a;
        return a;
    }
};
