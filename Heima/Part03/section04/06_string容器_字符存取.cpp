#include <iostream>

using namespace std;

void test1() {
    string s = "hello";
    cout << "s = " << s << endl;
    // 1. 通过[]访问单个字符
    for (int i = 0; i < s.size(); i++)
        cout << s[i] << " ";
    cout << endl;
    // 2. 通过at方式访问
    for (int i = 0; i < s.size(); i++)
        cout << s.at(i) << " ";
    cout << endl;

    // 修改单个字符
    s[0] = 'x';
    s.at(1) = 'x';
    cout << s << endl;
}

int main() {
    test1();
    return 0;
}