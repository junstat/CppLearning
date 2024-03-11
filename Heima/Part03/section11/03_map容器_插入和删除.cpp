#include "../utils/print.h"

void test1() {
    map<int, int> mp;
    // 插入
    // 第一种
    mp.insert(pair<int, int>(1, 10));
    // 第二种
    mp.insert(make_pair(2, 20));
    // 第三种
    mp.insert(map<int, int>::value_type(3, 30));
    // 第四种
    mp[4] = 40;
    print<int, int>(mp);

    // 删除
    mp.erase(mp.begin());
    print<int, int>(mp);

    mp.erase(3);  // 按key删除
    print<int, int>(mp);

    // 清空
    mp.clear();
    print<int, int>(mp);
}

int main() {
    test1();
    return 0;
}