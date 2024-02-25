#include <iostream>

using namespace std;

class Base {
public:
    int a;
protected:
    int b;
private:
    int c;
};

class Son : public Base {
public:
    int d;
};

void test1() {
    // 父类中所有非静态成员属性都会被子类继承下去
    // 父类中私有成员属性 是被编译器给隐藏了 因此是访问不到 但是确实被继承了
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(Son) = " << sizeof(Son) << endl;
}

int main() {
    test1();
    return 0;
}