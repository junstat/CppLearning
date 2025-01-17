#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        unordered_map<int, int> cnt;
        for (int num: nums) {
            cnt[num]++;
            if (cnt[num] == 3) {
                cnt.erase(num);
            }
        }
        return cnt.begin()->first;
    }
};