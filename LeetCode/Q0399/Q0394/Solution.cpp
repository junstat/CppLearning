#include <string>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string ans;
        int n = s.size();
        while (idx < n && s[idx] != ']') {
            if (!isdigit(s[idx])) ans.push_back(s[idx++]);
            else {
                int k = 0;
                while (idx < n && isdigit(s[idx]))
                    k = k * 10 + s[idx++] - '0';
                idx++;
                string pre = decodeString(s);
                idx++;
                while (k-- > 0)
                    ans += pre;
            }
        }
        return ans;
    }

    int idx = 0;
};