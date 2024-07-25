#include <string>
#include <algorithm>

using namespace std;

class Solution {

    int countOps(string s, string lastTwoDigs) {
        int indx = s.size() - 1;
        bool zeroExist = false;
        if (s.find('0') != string::npos)zeroExist = true;
        while (indx >= 0 and s[indx] != lastTwoDigs[1]) indx -= 1;
        if (indx == -1) return s.size() - ((zeroExist) ? 1 : 0);
        indx--;
        while (indx >= 0 and s[indx] != lastTwoDigs[0]) indx -= 1;
        if (indx == -1) return s.size() - ((zeroExist) ? 1 : 0);
        return (s.size() - 1 - indx) - 1;//substracting one for lastTwoDigs[0]
    }

public:
    int minimumOperations(string num) {
        return min(min(countOps(num, "00"), countOps(num, "25")), min(countOps(num, "50"), countOps(num, "75")));
    }
};