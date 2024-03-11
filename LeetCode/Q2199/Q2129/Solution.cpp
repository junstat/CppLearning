#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string capitalizeTitle(string title) {
        transform(title.begin(), title.end(), title.begin(), ::tolower);

        int n = title.size(), lastSpaceIdx = -1;
        for (int i = 0; i < n; ++i) {
            if (title[i] == ' ' || i == n - 1) {
                int t = i != n - 1 ? 1 : 0;
                if (i - lastSpaceIdx - t > 2)
                    title[lastSpaceIdx + 1] = toupper(title[lastSpaceIdx + 1]);
                lastSpaceIdx = i;
            }
        }
        return title;
    }
};

int main() {
    string s = "hi jun";
    Solution sol;
    cout << sol.capitalizeTitle(s) << endl;
    s = "capiTalIze tHe titLe";
    cout << sol.capitalizeTitle(s) << endl;
    s = "First leTTeR of EACH Word";
    cout << sol.capitalizeTitle(s) << endl;
    s = "i lOve leetcode";
    cout << sol.capitalizeTitle(s) << endl;

}