#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mp(128, 0);
        for (auto c: t) mp[c]++;
        int counter = t.length(), begin = 0, end = 0, d = INT_MAX, head = 0;
        while (end < s.length()) {
            if (mp[s[end++]]-- > 0) counter--; // in t
            while (counter == 0) { // valid
                if (end - begin < d) d = end - (head = begin);
                if (mp[s[begin++]]++ == 0) counter++;
            }
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};