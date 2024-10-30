#include <vector>

using namespace std;

class Template {
public:
    // 当check(mid) == true调整的是l时:
    // 计算mid的方式应该为mid = l+r+1 >> 1
    // Q0116: 为啥修改左指针l的时候要进行+1操作？
    // +1操作主要是为了避免发生死循环，因为>>和直接使用/一样
    // 都属于下取整操作
    // 考虑 l=0，r=1的简单情况，如果不+1的话
    // l+r>>1 等于0+1/2，l仍然是0，陷入死循环
    int binarySearch(vector<int> &nums, int target) {
        long l = 0, r = nums.size() - 1;
        while (l < r) {
            long mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return nums[r] == target ? r : -1;
    }

    int binarySearch2(vector<int> &nums, int target) {
        long l = 0, r = nums.size() - 1;
        while (l < r) {
            long mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[r] == target ? r : -1;
    }

    bool check(long mid) {
        return false;
    }
};