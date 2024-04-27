#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxArrayValue(vector<int> &nums) {
        long long ans = 0;
        int n = nums.size();
        vector<long long> arr(n);
        for (int i = 0; i < n; i++) arr[i] = nums[i];
        for (int i = n - 1; i > 0; i--)
            if (arr[i - 1] <= arr[i])
                arr[i - 1] = arr[i] + arr[i - 1];
        return *max_element(arr.begin(), arr.end());
    }
};