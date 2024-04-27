#include <iostream>

using namespace std;

// 查找
void test1() {
    // find
    string s1 = "abcdefg";
    // auto pos = s1.find("de");
    auto pos = s1.find("df");
    if (pos == -1) {
        cout << "not found" << endl;
    } else {
        cout << "找到字符串，pos = " << pos << endl;
    }

    // rfind
    pos = s1.rfind("de");
    if (pos == -1) {
        cout << "not found" << endl;
    } else {
        cout << "找到字符串，pos = " << pos << endl;
    }

}

// 替换
void test2() {
    string s1 = "abcdefg";
    // 从1号位置起，3个字符，替换为1111
    s1.replace(1, 3, "1111");
    cout << s1 << endl;
}

int main() {
    test2();
    return 0;
}
