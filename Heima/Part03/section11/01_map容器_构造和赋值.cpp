#include "../utils/print.h"

void test1() {
    map<int, int> mp = {
            {1, 10},
            {2, 20},
            {3, 30},
            {4, 40}
    };

    print<int, int>(mp);

    // 拷贝构造
    map<int, int> mp2(mp);
    print<int, int>(mp2);

    // 赋值
    map<int, int> mp3;
    mp3 = mp;
    print<int, int>(mp3);
}

int main() {
    test1();
    return 0;
}