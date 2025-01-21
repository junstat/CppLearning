#include <cinttypes>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        int cnt = 32;
        while (cnt-- > 0) {
            ans <<= 1;
            ans += (n & 1);
            n >>= 1;
        }
        return ans;
    }
};