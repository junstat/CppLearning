#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans(word.size());
        long long x = 0;
        for (int i = 0; i < word.size(); ++i) {
            x = (x * 10 + (word[i] - '0')) % m;
            ans[i] = x == 0;
        }
        return ans;
    }
};