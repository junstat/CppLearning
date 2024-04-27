#include <iostream>
#include <string>

using namespace std;

/**
 * string()
 * string(const string& str)
 * string(const char* s)
 * string(int n, char c)
 */

void test1() {
    string s1; // 默认构造
    string s2("hello world");
    string s3(s2);
    string s4(5, 'c');
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s4 = " << s4 << endl;
}

int main() {
    test1();
    return 0;
}