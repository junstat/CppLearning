#include <iostream>

using namespace std;

int main() {
    // 1. 字符型变量创建方式
    char ch = 'A';
    // 2. 字符型变量所占用内存大小
    cout << "char类型变量所占内存大小为：" << sizeof(char) << endl;
    // 3. 字符型变量常见错误
    // char ch = 'ab'; // 错误，一个字符型变量只能存储一个字符
    // char ch = "ab"; // 错误，字符型变量不能存储字符串

    // 4. 字符型变量对应ASCII编码
    // a -> 97
    // A -> 65
    cout << "ch的ASCII编码为：" << (int) ch << endl;
    return 0;
}