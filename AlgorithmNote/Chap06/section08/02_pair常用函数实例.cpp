#include <iostream>
#include <utility>

using namespace std;

// 比较操作
// 两个pair类型数据可以直接使用 ==、!=、<、<=、>、>= 比较运算符进行比较。
// 比较规则是先以first的大小做为标准，只有当first相等时才去判别second的大小。

int main() {
    pair<int, int> p1(5, 10);
    pair<int, int> p2(5, 15);
    pair<int, int> p3(10, 5);
    if (p1 < p3) cout << "p1 < p3" << endl;
    if (p1 <= p3) cout << "p1 <= p3" << endl;
    if (p1 < p2) cout << "p1 < p2" << endl;
    return 0;
}