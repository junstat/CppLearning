#include <vector>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> seen;
        set<string> repeated;
        for (int i = 0; i + 9 < s.length(); ++i) {
            string ten = s.substr(i, 10);
            if (seen.count(ten)) {
                repeated.insert(ten);
            } else {
                seen.insert(ten);
            }
        }
        vector<string> ans(repeated.begin(), repeated.end());
        return ans;
    }
};