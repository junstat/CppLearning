#include <string>

using namespace std;

class Solution {
public:
    bool isCircularSentence(string s) {
        auto n = s.size();
        for (auto i = 0; i < n; ++i) {
            if (s[i] == ' ' && s[i - 1] != s[i + 1])
                return false;
        }
        return s[0] == s[n - 1];
    }
};