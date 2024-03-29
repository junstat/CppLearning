#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 普通函数
void print(int val) {
    cout << val << " ";
}

// 仿函数
class Print {
public:
    void operator()(int val) {
        cout << val << " ";
    }
};

void test1() {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), print);
    cout << endl;

    for_each(v.begin(), v.end(), Print());
    cout << endl;
}

int main() {
    test1();
    return 0;
}