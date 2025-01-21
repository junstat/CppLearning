#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> nums1;
        vector<int> nums2;
        split(version1, nums1);
        split(version2, nums2);

        int len = max(nums1.size(), nums2.size());
        for (int i = 0; i < len; i++) {
            int a = i < nums1.size() ? nums1[i] : 0;
            int b = i < nums2.size() ? nums2[i] : 0;
            if (a < b) {
                return -1;
            } else if (a > b) {
                return 1;
            }
        }
        return 0;
    }

    void split(string &s, vector<int> &nums) {
        string num;
        for (char i: s) {
            if (i == '.') {
                nums.push_back(stoi(num));
                num = "";
            } else {
                num += i;
            }
        }
        nums.push_back(stoi(num));
    }
};