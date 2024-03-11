#include "../utils/print.h"

void test1() {
    map<int, int> mp = {
            {1, 10},
            {2, 20},
            {3, 30},
            {3, 40}
    };
    auto pos = mp.find(3);

    if (pos != mp.end()) {
        cout << "查到了元素 key = " << (*pos).first
             << "value = " << (*pos).second << endl;
    } else {
        cout << "未找到元素" << endl;
    }

    // 统计
    // map不允许插入重复key元素，count统计结果，要么0要么1
    auto num = mp.count(3);
    cout << "num = " << num << endl;
}

int main() {
    test1();
    return 0;
}