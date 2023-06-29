#include <vector>
#include <cctype>
#include <string>

using namespace std;

class Solution {
public:
    int maximumValue(vector<string> &strs) {
        int ans = INT_MIN;
        for (const auto &s: strs) {
            if (all_of(s.begin(), s.end(), isdigit)) {
                ans = max(ans, stoi(s));
            } else {
                ans = max(ans, (int) s.length());
            }
        }
        return ans;
    }
};