#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<int, int> freq;
        for (char c: s) ++freq[c];
        string ans;
        ans.reserve(s.size());
        for (char ch = 'z'; ch >= 'a'; --ch) {
            for (int i = 0; i < freq[ch]; ++i) {
                ans.push_back(ch);
            }
        }

        int cnt = 1;
        // 双指针
        for (int left = 1, right = 2; left < ans.size(); ++left) {
            if (ans[left - 1] != ans[left]) {
                cnt = 1;
            } else {
                ++cnt;
                if (cnt > repeatLimit) {
                    right = max(right, left + 1);
                    while (right < ans.size() && ans[left] == ans[right])++right;
                    if (right < s.size()) {
                        swap(ans[left], ans[right]);
                        cnt = 1;
                    } else {
                        ans.erase(ans.begin() + left, ans.end());
                        break;
                    }
                }
            }
        }
        return ans;
    }
};