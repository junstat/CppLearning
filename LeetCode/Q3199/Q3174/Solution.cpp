#include <string>

using namespace std;


class Solution {
public:
    string clearDigits(string s) {
        string ans;
        for (const auto &c: s) {
            if (isdigit(c) && !ans.empty()) {
                ans.pop_back();
            } else {
                ans += c;
            }
        }
        return ans;
    }
};