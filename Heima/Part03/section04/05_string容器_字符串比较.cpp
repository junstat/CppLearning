#include <iostream>

using namespace std;

void test1() {
    string s1 = "xello";
    string s2 = "hello";

    if (s1.compare(s2) == 0) {
        cout << "s1 等于 s2" << endl;
    } else if (s1.compare(s2) > 0) {
        cout << "s1 大于 s2" << endl;
    } else {
        cout << "s1 小于 s2" << endl;
    }
}

int main() {
    test1();
    return 0;
}