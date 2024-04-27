#include "../utils/print.h"

void test1() {
    vector<int> v1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<int> v2;
    v2.resize(v1.size());
    copy(v1.begin(), v1.end(), v2.begin());
    print(v2);
}

int main() {
    test1();
    return 0;
}