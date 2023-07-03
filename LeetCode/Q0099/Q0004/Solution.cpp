#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int tot = nums1.size() + nums2.size();
        if (tot % 2 == 0) {
            int left = find(nums1, 0, nums2, 0, tot / 2);
            int right = find(nums1, 0, nums2, 0, tot / 2 + 1);
            return (left + right) / 2.0;
        } else return find(nums1, 0, nums2, 0, tot / 2 + 1);
    }

    int find(vector<int> &n1, int i, vector<int> &n2, int j, int k) {
        if (n1.size() - i > n2.size() - j) return find(n2, j, n1, i, k);
        if (i >= n1.size()) return n2[j + k - 1];
        if (k == 1) return min(n1[i], n2[j]);
        else {
            int si = min(i + k / 2, (int) n1.size()), sj = j + k - k / 2;
            if (n1[si - 1] > n2[sj - 1]) return find(n1, i, n2, sj, k - (sj - j));
            else return find(n1, si, n2, j, k - (si - i));
        }
    }
};