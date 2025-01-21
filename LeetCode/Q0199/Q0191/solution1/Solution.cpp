class Solution {
public:
    int hammingWeight(int n) {
        if (n == 0) return 0;
        int cnt = 0;
        for (int i = 0; i < 32; ++i) {
            cnt += n & 1;
            n >>= 1;
        }
        return cnt;
    }
};