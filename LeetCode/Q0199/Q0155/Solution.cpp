#include <stack>

using namespace std;

class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        data.push(val);
        if (help.empty() || help.top() >= val) {
            help.push(val);
        } else {
            help.push(help.top());
        }
    }

    void pop() {
        data.pop();
        help.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return help.top();
    }

    stack<int> data;
    stack<int> help;
};
