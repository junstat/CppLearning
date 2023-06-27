#include <queue>

using namespace std;

class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        data.push(x);
        for (int i = 0; i < data.size() - 1; i++)
            data.push(data.front()), data.pop();
    }

    int pop() {
        int res = data.front();
        data.pop();
        return res;
    }

    int top() {
        return data.front();
    }

    bool empty() {
        return data.empty();
    }

private:
    queue<int> data;
};