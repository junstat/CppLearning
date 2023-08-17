#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> d;
        d.push(-1);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') d.push(i);
            else {
                d.pop();
                if (d.empty()) d.push(i);
                else ans = max(ans, i - d.top());
            }
        }
        return ans;
    }
};