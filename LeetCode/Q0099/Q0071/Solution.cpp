#include <string>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string item;
        stack<string> stk;
        while (getline(ss, item, '/')) {
            if (item == "..") {
                if (!stk.empty()) {
                    stk.pop();
                }
            } else if (item != "" && item != ".") {
                stk.push(item);
            }
        }
        string ans;
        while (!stk.empty()) {
            ans = "/" + stk.top() + ans;
            stk.pop();
        }
        return ans.empty() ? "/" : ans;
    }
};