#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Transform {
public:
    int operator()(int v) {
        return v + 100;
    }
};

class Print {
public:
    void operator()(int val) {
        cout << val << " ";
    }
};

void test1() {
    vector<int> v;
    for (int i = 0; i < 10; ++i)
        v.push_back(i);

    vector<int> dest;
    dest.resize(v.size());

    transform(v.begin(), v.end(), dest.begin(), Transform());

    for_each(dest.begin(), dest.end(), Print());
    cout << endl;
}

int main() {
    test1();
    return 0;
}