#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> str = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    int romanToInt(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0, j = 0; i < str.size() && j < n; i++) {
            int cv = val[i];
            auto cs = str[i];
            int size = cs.size();
            while (j + size <= n && s.substr(j, size) == (cs)) {
                ans += cv;
                j += size;
            }
        }
        return ans;
    }
};