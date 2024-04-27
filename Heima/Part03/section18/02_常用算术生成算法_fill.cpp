#include "../utils/print.h"

void test1() {
    vector<int> v(10);

    fill(v.begin(), v.end(), 100);
    print(v);
}

int main() {
    test1();
    return 0;
}