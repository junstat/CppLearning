#include "../utils/print.h"
#include <set>

void test1() {
    set<int> s1 = {10, 40, 30, 20, 30};

    print<set<int>>(s1);

    set<int> s2(s1);
    print<set<int>>(s2);

    // 赋值
    set<int> s3;
    s3 = s2;
    print<set<int>>(s3);
}

int main() {
    test1();
    return 0;
}