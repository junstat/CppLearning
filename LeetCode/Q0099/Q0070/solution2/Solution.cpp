class Solution {
public:
    int climbStairs(int n) {
        return fib(n, 1, 1);
    }

    long fib(int n, long a, long b) {
        return n == 0 ? a : fib(n - 1, b, a + b);
    }
};