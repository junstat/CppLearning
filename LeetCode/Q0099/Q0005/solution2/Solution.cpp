#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return s;
        string t = preProcess(s);
        int n = t.length();
        int p[n];
        int c = 0, r = 0, len = 1, start = 0;
        for (int i = 1; i < n - 1; i++) {
            int iM = 2 * c - i;
            p[i] = i < r ? min(r - i, p[iM]) : 0;
            while (t[i + p[i] + 1] == t[i - p[i] - 1]) p[i]++;
            if (i + p[i] > r) {
                c = i;
                r = i + p[i];
            }
            if (p[i] > len) {
                len = p[i];
                start = (i - p[i]) / 2;
            }
        }
        return s.substr(start, len);
    }

private:
    string preProcess(string s) {
        int n = s.length();
        if (n == 0) return "^$";
        string ans = "^";
        for (const auto &c: s) {
            ans += "#";
            ans += c;
        }
        ans += "#$";
        return ans;
    }
};