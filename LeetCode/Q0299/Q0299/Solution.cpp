#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        // int[] nums = new int[10];
        vector<int> nums(10);
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) bulls++;
            else {
                if (nums[secret[i] - '0']++ < 0) cows++;
                if (nums[guess[i] - '0']-- > 0) cows++;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};