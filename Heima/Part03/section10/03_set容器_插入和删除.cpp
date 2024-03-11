#include "../utils/print.h"

void test1() {
    set<int> s1 = {30, 10, 20, 40};
    print<set<int>>(s1);

    s1.erase(s1.begin());
    print<set<int>>(s1);

    s1.erase(30);
    print<set<int>>(s1);

    s1.erase(s1.begin(), s1.end());
    print<set<int>>(s1);
}

int main() {
    test1();
    return 0;
}