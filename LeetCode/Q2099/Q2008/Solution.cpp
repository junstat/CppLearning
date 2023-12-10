#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>> &rides) {
        vector<vector<pii>> rideStartAt(n);
        for (const auto &ride: rides) {
            int s = ride[0], e = ride[1], t = ride[2];
            rideStartAt[s].push_back({e, e - s + t});
        }

        vector<ll> f(n + 1);
        for (int i = n - 1; i >= 1; --i) {
            for (auto &[e, d]: rideStartAt[i]) {
                f[i] = max(f[i], f[e] + d);
            }
            f[i] = max(f[i], f[i + 1]);
        }
        return f[1];
    }
};