#include <stack>
#include <string>

using namespace std;

class Solution {
private:
    stack<char> st;
public:
    char stackPop() {
        char res = st.top();
        st.pop();
        return res;
    }

    bool isValid(string s) {
        for (char &c: s) {
            if (c == '(') st.push(')');
            else if (c == '[') st.push(']');
            else if (c == '{') st.push('}');
            else if (st.empty() || stackPop() != c) return false;
        }
        return st.empty();
    }
};