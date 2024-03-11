#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    long long kSum(vector<int> &nums, int k) {
        long sum = 0L;
        for (int &x: nums) {
            if (x >= 0) {
                sum += x;
            } else {
                x = -x;
            }
        }
        sort(nums.begin(), nums.end());

        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<>> pq;
        pq.emplace(0, 0); // 空子序列
        while (--k) {
            auto [s, i] = pq.top();
            pq.pop();
            if (i < nums.size()) {
                // 在子序列的末尾添加 nums[i]
                pq.emplace(s + nums[i], i + 1); // 下一个添加/替换的元素下标为 i+1
                if (i) { // 替换子序列的末尾元素为 nums[i]
                    pq.emplace(s + nums[i] - nums[i - 1], i + 1);
                }
            }
        }
        return sum - pq.top().first;
    }
};
