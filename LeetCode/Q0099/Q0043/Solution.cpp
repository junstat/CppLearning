#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> res(num1.size() + num2.size(), 0);
        for (int i = num1.size() - 1; i >= 0; i--) {
            for (int j = num2.size() - 1; j >= 0; j--) {
                int r = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                r += res[p2];
                res[p1] += r / 10;
                res[p2] = r % 10;
            }
        }
        string ans;
        for (int r: res) {
            if (ans.empty() && r == 0) continue;
            ans.push_back(r + '0');
        }
        return ans.empty() ? "0" : ans;
    }
};