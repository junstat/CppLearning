#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int magicTower(vector<int> &nums) {
        int sum = 1;
        for (int num: nums) sum += num;
        if (sum <= 0) return -1;

        long rest = 1;
        int ans = 0;
        priority_queue<int, vector<int>, greater<>> q;
        for (int num: nums) {
            if (num < 0) {
                q.push(num);
                if (rest + num <= 0) {
                    ans++;
                    rest -= q.top();
                    q.pop();
                }
            }
            rest += num;
        }
        return ans;
    }
};