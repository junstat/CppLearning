#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int sign = 1, base = 0, i = 0;
        while (i < s.size()&& s[i] == ' ') i++;
        if (i == s.size()) return 0;
        if (s[i] == '-' || s[i] == '+') sign = s[i++] == '-' ? -1 : 1;
        while (i < s.size()&& s[i] >= '0' && s[i] <= '9') {
            int a = s[i++] - '0';
            if (base > INT_MAX / 10 || (base == INT_MAX / 10 && a > INT_MAX % 10))
                return sign == 1 ? INT_MAX : INT_MIN;
            base = 10 * base + a;
        }
        return base * sign;
    }
};