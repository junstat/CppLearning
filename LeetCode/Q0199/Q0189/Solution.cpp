#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        auto start = nums.begin(), end = nums.end();
        k %= nums.size();
        reverse(start, end);
        reverse(start, start + k);
        reverse(start + k, end);
    }
};