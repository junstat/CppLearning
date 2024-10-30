#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <functional>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        unordered_map<string, function<int(int, int)>> operatorMap = {
                {"+", [](int a, int b) { return a + b; }},
                {"-", [](int a, int b) { return a - b; }},
                {"*", [](int a, int b) { return a * b; }},
                {"/", [](int a, int b) { return a / b; }},
        };
        stack<int> st;
        int op1, op2;
        for (string &s: tokens) {
            if (!operatorMap.count(s)) {
                st.push(stoi(s));
            } else {
                op1 = st.top(), st.pop();
                op2 = st.top(), st.pop();
                st.push(operatorMap[s](op2, op1));
            }
        }
        return st.top();
    }
};