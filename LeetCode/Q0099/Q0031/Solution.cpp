#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int n = nums.size(), k = n - 1;
        while (k - 1 >= 0 && nums[k - 1] >= nums[k]) k--;
        if (k == 0) reverse(nums, 0, n - 1);
        else {
            int u = k;
            while (u + 1 < n && nums[u + 1] > nums[k - 1]) u++;
            swap(nums, k - 1, u);
            reverse(nums, k, n - 1);
        }
    }

    void reverse(vector<int> &nums, int a, int b) {
        while (a < b) swap(nums, a++, b--);
    }

    void swap(vector<int> &nums, int a, int b) {
        int c = nums[a];
        nums[a] = nums[b];
        nums[b] = c;
    }
};