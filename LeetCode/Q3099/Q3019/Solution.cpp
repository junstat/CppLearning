#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countKeyChanges(string s) {
        int ans = 0;
        for (int i = 1; i < s.length(); i++) {
            ans += (s[i - 1] & 31) != (s[i] & 31);
        }
        return ans;
    }
};
