#include <stack>

using namespace std;

class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        input.push(x);
    }

    int pop() {
        if (!empty()) {
            int res = peek();
            output.pop();
            return res;
        }
        return -1; // never reach
    }

    int peek() {
        if (output.empty())
            while (!input.empty())
                output.push(input.top()), input.pop();
        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }

private:
    stack<int> input, output;
};
