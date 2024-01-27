#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;
    long dp[23][401][2];

    long solve(int idx, int sum, bool tight, const int &min_sum, const int &max_sum, string &s) {
        if (idx == s.size())
            return sum >= min_sum and sum <= max_sum;

        if (dp[idx][sum][tight] != -1)
            return dp[idx][sum][tight];

        long ans = 0;
        if (tight) {
            for (int i = 0; i <= s[idx] - '0'; i++) {
                if ((s[idx] - '0') == i)
                    ans = (ans + solve(idx + 1, sum + i, true, min_sum, max_sum, s)) % mod;
                else
                    ans = (ans + solve(idx + 1, sum + i, false, min_sum, max_sum, s)) % mod;
            }
        } else {
            for (int i = 0; i <= 9; i++)
                ans = (ans + solve(idx + 1, sum + i, false, min_sum, max_sum, s)) % mod;
        }
        return dp[idx][sum][tight] = ans;
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp, -1, sizeof(dp));
        long upper = solve(0, 0, true, min_sum, max_sum, num2);
        memset(dp, -1, sizeof(dp));
        long lower = solve(0, 0, true, min_sum, max_sum, num1);

        int sum = 0;
        for (auto i: num1)
            sum += (i - '0');

        if (sum >= min_sum and sum <= max_sum)
            lower--;

        return ((upper - lower) + mod) % mod;
    }
};