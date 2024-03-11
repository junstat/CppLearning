#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        long ans = 1;
        for (int i = 0; i < n; ++i)
            ans = ans * (4 * i + 2) / (i + 2);
        return ans;
    }
};