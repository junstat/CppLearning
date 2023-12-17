#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int first = 0, second = 0;
        for (int i = 2; i <= cost.size(); ++i) {
            int cur = min(first + cost[i - 2], second + cost[i - 1]);
            first = second;
            second = cur;
        }
        return second;
    }
};