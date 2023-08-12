#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int flipgame(vector<int> &fronts, vector<int> &backs) {
        set<int> same;
        for (int i = 0; i < fronts.size(); ++i)
            if (fronts[i] == backs[i])
                same.insert(fronts[i]);
        int ans = 3000;
        for (const auto &i: fronts) {
            if (same.find(i) == same.end())
                ans = min(ans, i);
        }
        for (const auto &i: backs) {
            if (same.find(i) == same.end())
                ans = min(ans, i);
        }
        return ans % 3000;
    }
};