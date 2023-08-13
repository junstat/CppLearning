#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string ans;
        auto s = strs[0];
        for (int i = 0; i < INT_MAX; ++i) {
            if (i >= s.size()) return ans;
            auto c = s[i];
            for (auto item: strs) {
                if (i >= item.size() || item[i] != c) return ans;
            }
            ans += c;
        }
        return ans;
    }
};