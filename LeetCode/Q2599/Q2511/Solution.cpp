#include <vector>

using namespace std;

class Solution {
public:
    int captureForts(vector<int> &forts) {
        int ans = 0, x = 0;
        for (int i = 0; i < forts.size(); ++i) {
            if (forts[i]) {
                if (forts[x] == -forts[i]) ans = max(ans, i - x - 1);
                x = i;
            }
        }
        return ans;
    }
};