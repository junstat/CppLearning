#include <string>

using namespace std;

class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ans;
        auto i = 0, j = 0;
        while (i < word1.size() && j < word2.size()) {
            if (word1.compare(i, word1.size() - i, word2, j, word2.size() - j) > 0)
                ans += word1[i++];
            else
                ans += word2[j++];
        }
        return ans + word1.substr(i) + word2.substr(j);
    }
};