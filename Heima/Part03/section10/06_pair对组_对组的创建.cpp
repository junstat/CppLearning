#include "../utils/print.h"

void test1() {
    // 第一种方式
    pair<string, int> p("tom", 20);
    cout << "name: " << p.first << ", age: " << p.second << endl;

    // 第二种方式
    pair<string, int> p2 = make_pair("jerry", 30);
    cout << "name: " << p2.first << ", age: " << p2.second << endl;
}

int main() {
    test1();
    return 0;
}