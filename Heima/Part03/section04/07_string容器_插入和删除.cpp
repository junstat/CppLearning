#include <iostream>

using namespace std;

void test1() {
    string s = "hello";
    // 插入
    s.insert(1, "111");
    cout << "s = " << s << endl;

    // 删除
    s.erase(1, 3);
    cout << "s = " << s << endl;
}

int main() {
    test1();
    return 0;
}