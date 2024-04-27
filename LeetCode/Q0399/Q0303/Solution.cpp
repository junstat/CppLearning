#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        accu.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            accu[i + 1] = accu[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return accu[right + 1] - accu[left];
    }

    vector<int> accu;
};
