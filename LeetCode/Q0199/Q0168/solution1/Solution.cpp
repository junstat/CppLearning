#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while (n > 0) {
            n -= 1;
            ans.append(1, char('A' + n % 26));
            n /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};