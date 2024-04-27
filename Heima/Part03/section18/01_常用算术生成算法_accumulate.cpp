#include "../utils/print.h"

void test1() {
    vector<int> v;
    for (int i = 0; i <= 100; ++i)
        v.push_back(i);
    auto total = accumulate(v.begin(), v.end(), 0);
    cout << "total = " << total << endl;
}

int main() {
    test1();
    return 0;
}