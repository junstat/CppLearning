#include<iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

void print(const vector<int> &v) {
    for_each(v.begin(), v.end(), [](int i) { cout << i << " "; });
    cout << endl;
}

void test1() {
    vector<int> v = {10, 30, 50, 20, 40};
    sort(v.begin(), v.end());
    print(v);

    sort(v.begin(), v.end(), greater<>());
    print(v);
}

int main() {
    test1();
    return 0;
}
