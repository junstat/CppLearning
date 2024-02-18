#include <iostream>
#include <string>

using namespace std;

int n; // 有效位数

string deal(string s, int &e) {
    int k = 0; // s的下标
    while (s.length() > 0 && s[0] == '0') {
        s.erase(s.begin());  // 去掉s的前导零
    }
    if (s[0] == '.') { // 去掉前导零后是小数点，说明s是小于1的小数
        s.erase(s.begin());
        while (s.length() > 0 && s[0] == '0') {
            s.erase(s.begin()); // 去掉小数点后非零位前的所有零
            e--;  // 每去掉一个0,指数e减1
        }
    }
    return "";
}

int main() {

    return 0;
}