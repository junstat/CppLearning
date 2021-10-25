#include <queue>
#include <iostream>

using namespace std;

class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        if (q1.empty()) {
            q1.push(x);
            while (!q2.empty())
                q1.push(q2.front()), q2.pop();
        } else {
            q2.push(x);
            while (!q1.empty())
                q2.push(q1.front()), q1.pop();
        }
    }

    int pop() {
        int res;
        if (!q1.empty())
            res = q1.front(), q1.pop();
        else
            res = q2.front(), q2.pop();
        return res;
    }

    int top() {
        return !q1.empty() ? q1.front() : q2.front();
    }

    bool empty() {
        return q1.empty() && q2.empty();
    }

private:
    queue<int> q1;
    queue<int> q2;
};

int main() {
    auto s = new MyStack();
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    while (!s->empty())
        cout << s->top() << endl, s->pop();

}