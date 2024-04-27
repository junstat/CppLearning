#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> nodes = split(preorder, ',');
        int diff = 1;
        for (const auto &node: nodes) {
            if (--diff < 0) return false;
            if (node != "#") diff += 2;
        }
        return diff == 0;
    }

    vector<string> split(const string &str, char delim) {
        vector<string> ans;
        stringstream ss(str);
        string buffer;
        while (getline(ss, buffer, delim)) {
            ans.push_back(buffer);
        }
        return ans;
    }
};
