#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        auto ans = 0;
        for (int start = 0, end = 0; end < s.length(); end++) {
            map[s[end]]++;
            while (map[s[end]] > 1) {
                map[s[start]]--;
                start++;
            }
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};