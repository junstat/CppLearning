#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int> &special) {
        sort(special.begin(), special.end());
        size_t n = special.size();
        int ans = max(special[0] - bottom, top - special[n - 1]);
        for (size_t i = 1; i < n; i++) {
            ans = max(ans, special[i] - special[i - 1] - 1);
        }
        return ans;
    }
};
