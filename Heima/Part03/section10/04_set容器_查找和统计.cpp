#include "../utils/print.h"

void test1() {
    set<int> s1 = {10, 30, 20, 40};

    auto pos = s1.find(30);
    if (pos != s1.end()) {
        cout << "找到元素: " << *pos << endl;
    } else {
        cout << "未找到元素" << endl;
    }
}

void test2() {
    set<int> s1 = {10, 30, 20, 40};

    auto num = s1.count(30);
    cout << "num = " << num << endl;
}

int main() {
    test2();
    return 0;
}