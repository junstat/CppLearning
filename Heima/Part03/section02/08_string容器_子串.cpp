#include <iostream>
#include <string>

using namespace std;

void test1() {
    string s = "abcdef";
    auto subStr = s.substr(1, 3);
    cout << "sub str = " << subStr << endl;
}

// 实用操作
void test2() {
    string email = "zhangsan@sina.com";
    // 从邮件中获取用户名信息
    auto pos = email.find('@');
    string username = email.substr(0, pos);
    cout << "username = " << username << endl;
}

int main() {
    test2();
    return 0;
}