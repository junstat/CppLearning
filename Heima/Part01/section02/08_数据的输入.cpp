#include <iostream>

using namespace std;

int main() {
    // 1. 整型
    int a = 0;
    cout << "请给整型变量a赋值：" << endl;
    cin >> a;
    cout << "整型变量a = " << a << endl;

    // 2. 浮点型
    float f = 3.14f;
    cout << "请给浮点型变量f赋值：" << endl;
    cin >> f;
    cout << "浮点型变量f = " << f << endl;

    // 3. 字符型
    char c = 'a';
    cout << "请给字符型变量c赋值：" << endl;
    cin >> c;
    cout << "字符型变量c = " << c << endl;

    // 4. 字符串型
    string s = "Hello, World!";
    cout << "请给字符串型变量s赋值：" << endl;
    cin >> s;
    cout << "字符串变量s = " << s << endl;

    // 5. 布尔型
    bool b = true;
    cout << "请给布尔型变量b赋值：" << endl;
    cin >> b;  // bool类型，只要非0均为true
    cout << "布尔型变量b = " << b << endl;

    return 0;
}