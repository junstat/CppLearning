#include <iostream>

using namespace std;

class Base {
public:
    Base(int a, int b, int c) : a(a), b(b), c(c) {}

    int a;
protected:
    int b;
private:
    int c;
};

class Son1 : public Base {
    // a 在子类中为 public 权限
    // b 在子类中为 protected 权限
public:
    Son1(int a, int b, int c) : Base(a, b, c) {}

    void func() {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        // cout << "c = " << c << endl; // 错误：无法访问private成员
    }
};

class Son2 : protected Base {
    // a,b 在子类中为protected权限
public:
    Son2(int a, int b, int c) : Base(a, b, c) {}

    void func() {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        // cout << "c = " << c << endl; // 错误：无法访问private成员
    }
};

class Son3 : private Base {
    // a,b 在子类中为private权限
public:
    Son3(int a, int b, int c) : Base(a, b, c) {}

    void func() {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        // cout << "c = " << c << endl; // 错误：无法访问private成员
    }
};

int main() {

    return 0;
}