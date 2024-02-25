#include <iostream>

using namespace std;

// 在C++中struct和class的唯一区别在于 默认访问权限
//  struct默认public，class默认private
class C1 {
    int a; // 默认是私有权限
};

struct C2 {
    int a; // 默认是公共权限
};

int main() {
    C1 c1;
    C2 c2;
    // c1.a = 10;
    // cout << "c1.a = " << c1.a << endl;
    c2.a = 10;
    cout << "c2.a = " << c2.a << endl;
    return 0;
}