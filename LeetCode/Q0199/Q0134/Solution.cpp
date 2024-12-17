#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int start = 0, tot = 0, tank = 0;
        for (int i = 0; i < gas.size(); ++i) {
            if ((tank = tank + gas[i] - cost[i]) < 0) {
                start = i + 1;
                tot += tank;
                tank = 0;
            }
        }
        return (tot + tank < 0) ? -1 : start;
    }
};