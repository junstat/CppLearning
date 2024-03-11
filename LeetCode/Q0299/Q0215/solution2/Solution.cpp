#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }

    int quickSelect(vector<int> &a, int l, int r, int index) {
        int q = randomPartition(a, l, r);
        if (q == index) return a[q];
        else
            return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
    }

    int randomPartition(vector<int> &a, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(a[r], a[i]);
        return partition(a, l, r);
    }

    int partition(vector<int> &a, int l, int r) {
        int x = a[r], i = l - 1;
        for (int j = l; j < r; ++j) {
            if (a[j] <= x) {
                swap(a[++i], a[j]);
            }
        }
        swap(a[i + 1], a[r]);
        return i + 1;
    }
};