#include "../utils/print.h"

void test1() {
    srand((unsigned int) time(nullptr));
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    random_shuffle(v.begin(), v.end());
    print(v);
}

int main() {
    test1();
    return 0;
}