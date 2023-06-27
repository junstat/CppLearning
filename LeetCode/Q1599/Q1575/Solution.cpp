#include <vector>

using namespace std;

class Solution {
public:
    const static int MOD = 1e9 + 7;

    int countRoutes(vector<int> &locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<long long >> dp(n, vector<long long>(fuel + 1, -1));
        return (int) solve(locations, start, finish, dp, fuel);
    }

    long long solve(vector<int> &locations, int u, int e, vector<vector<long long >> &dp, int fuel) {
        if (fuel < 0) return 0;
        if (dp[u][fuel] != -1) return dp[u][fuel];
        long long ans = (u == e) ? 1 : 0;
        for (int next = 0; next < locations.size(); ++next) {
            if (next == u) continue;
            ans = (ans + solve(locations, next, e, dp, fuel - abs(locations[u] - locations[next])) % MOD) % MOD;
        }
        return dp[u][fuel] = ans;
    }
};