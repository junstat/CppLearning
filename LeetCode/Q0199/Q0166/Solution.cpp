#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using ll = long long;

    string fractionToDecimal(int numerator, int denominator) {
        ll a = numerator, b = denominator;
        if (a % b == 0) return to_string(a / b);
        string ans;
        if (a * b < 0) ans.append("-");
        a = abs(a);
        b = abs(b);
        ans.append(to_string(a / b)).append(".");

        a %= b;
        unordered_map<ll, int> mp;
        while (a != 0) {
            mp[a] = static_cast<int>(ans.size());
            a *= 10;
            ans.append(to_string(a / b));
            a %= b;
            if (mp.count(a)) {
                int u = mp[a];
                return ans.substr(0, u) + "(" + ans.substr(u) + ")";
            }
        }
        return ans;
    }
};