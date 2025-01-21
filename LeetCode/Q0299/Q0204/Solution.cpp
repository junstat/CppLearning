#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        vector<bool> isPrime(n, false);
        int cnt = n / 2;
        for (int i = 3; i * i < n; i += 2) {
            if (isPrime[i]) continue;
            for (int j = i * i; j < n; j += 2 * i) {
                if (!isPrime[j]) {
                    isPrime[j] = true;
                    --cnt;
                }
            }
        }
        return cnt;
    }
};