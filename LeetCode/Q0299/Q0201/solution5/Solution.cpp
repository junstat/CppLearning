class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == n) return m;
        int i = m ^ n;
        i |= (i >> 1);
        i |= (i >> 2);
        i |= (i >> 4);
        i |= (i >> 8);
        i |= (i >> 16);
        return m & ~i;
    }
};