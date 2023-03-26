#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool findSubarrays(vector<int> &nums) {
        int n = nums.size();
        if (n <= 2) {
            return false;
        }
        unordered_set<int> s;
        for (int i = 0; i < n - 1; i++) {
            int sum = nums[i] + nums[i + 1];
            if (s.count(sum)) {
                return true;
            }
            s.insert(sum);
        }
        return false;
    }
};