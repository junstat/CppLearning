#include <vector>

using namespace std;

namespace Q3151 {
    class Solution {
    public:
        bool isArraySpecial(vector<int> &nums) {
            for (int i = 1; i < nums.size(); ++i) {
                int pre = nums[i - 1] & 1, cur = nums[i] & 1;
                if (pre == cur) {
                    return false;
                }
            }
            return true;
        }
    };
}

//int main() {
//    Q3151::Solution s;
//    vector<int> nums1 = {1};
//    vector<int> nums2 = {2, 1, 4};
//    vector<int> nums3 = {4, 3, 1, 6};
//    cout << s.isArraySpecial(nums1) << endl;
//    cout << s.isArraySpecial(nums2) << endl;
//    cout << s.isArraySpecial(nums3) << endl;
//    return 0;
//}