#include "../utils/print.h"

void test1() {
    set<int> s;
    pair<set<int>::iterator, bool> ret = s.insert(10);

    if (ret.second) {
        cout << "第一次插入成功." << endl;
    } else {
        cout << "第一次插入失败." << endl;
    }

    ret = s.insert(10);
    if (ret.second) {
        cout << "第二次插入成功." << endl;
    } else {
        cout << "第二次插入失败." << endl;
    }

    multiset<int> ms;

    ms.insert(10);
    ms.insert(10);
    ms.insert(10);
    ms.insert(10);

    print<multiset<int>>(ms);
}

int main() {
    test1();
    return 0;
}