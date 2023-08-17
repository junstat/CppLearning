#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        deque<int> d;
        for (int i = 0; i < k; ++i) {
            while (!d.empty() && nums[i] >= nums[d.back()])
                d.pop_back();
            d.push_back(i);
        }
        vector<int> ans(n - k + 1, 0);
        ans[0] = nums[d.front()];
        for (int i = k; i < n; ++i) {
            while (!d.empty() && nums[i] >= nums[d.back()])
                d.pop_back();
            d.push_back(i);
            while (d.front() <= i - k) d.pop_front();
            ans[i - k + 1] = nums[d.front()];
        }
        return ans;
    }
};