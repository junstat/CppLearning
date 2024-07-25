#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        nums.resize(1010, 0);
        int n =  ops.size(), idx = 0;
        for (int i = 0; i < n; i++, idx++) {
            if (ops[i] == "+") {
                nums[idx] = nums[idx - 1] + nums[idx - 2];
            } else if (ops[i] == "D") {
                nums[idx] = nums[idx - 1] * 2;
            } else if (ops[i] == "C") {
                idx -= 2;
            } else {
                nums[idx] = stoi(ops[i]);
            }
        }
        int ans = 0;
        for (int i = 0; i < idx; i++) ans += nums[i];
        return ans;
    }

    vector<int> nums;
};