#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> str = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string intToRoman(int x) {
        string ans;
        for (int i = 0; i < val.size() && x > 0; i++) {
            int cv = val[i];
            auto cs = str[i];
            while (x >= cv) {
                ans.append(cs);
                x -= cv;
            }
        }
        return ans;
    }
};