#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test1() {
    vector<int> v;
    for (int i = 0; i < 10; ++i)
        v.push_back(i);

    auto ret = binary_search(v.begin(), v.end(), 9);
    if (ret) {
        cout << "found"<< endl;
    } else {
        cout << "not found" << endl;
    }
}

int main() {
    test1();
    return 0;
}