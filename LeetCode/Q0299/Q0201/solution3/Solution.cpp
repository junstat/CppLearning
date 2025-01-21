class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == right) return left;
        return left & ~highestOneBit(left ^ right) + 1;
    }

    int highestOneBit(int n) {
        if (n == 0) return 0;
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;
        return n - (n >> 1);
    }
};