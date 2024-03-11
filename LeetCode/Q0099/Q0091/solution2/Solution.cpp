#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        s = " " + s;
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            int a = s[i] - '0', b = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (1 <= a && a <= 9) f[i] = f[i - 1];
            if (10 <= b && b <= 26) f[i] += f[i - 2];
        }
        return f[n];
    }
};