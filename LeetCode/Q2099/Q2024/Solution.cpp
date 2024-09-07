#include <string>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k_) {
        s = answerKey;
        n = s.size(), k=k_;
        return max(getCnt('T'), getCnt('F'));
    }

    int getCnt(char c) {
        int ans = 0;
        for (int i = 0 , j = 0 , cnt = 0; i < n; ++i) {
            if (s[i] == c) cnt++;
            while (cnt > k) {
                if (s[j] == c) cnt--;
                j++;
            }
            ans = max(ans, i - j  + 1);
        }
        return ans;
    }

private:
    string s;
    int n, k;
};