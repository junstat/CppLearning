#include <vector>
#include <set>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int N = 0x3FFFFFFF;

    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, bool> seen;
        vector<string> ans;
        for (int cur = 0, i = 0; i < s.size(); ++i) {
            cur = cur << 3 & N | (s[i] & 7);
            if (!seen.count(cur)) {
                seen[cur] = true;
                continue;
            }

            if (seen[cur]) {
                ans.push_back(s.substr(i - 9, 10jj));
                seen[cur] = false;
            }
        }
        return ans;
    }
};