#include <iostream>

using namespace std;

template<class T>
class Base {
    T m;
};

// 必须要知道父类中的T类型，才能继承给子类
class Son : public Base<int> {

};

void test1() {
    Son s1;
}

// 如果想灵活指定父类中T类型，子类也需要变类模板
template<class T1, class T2>
class Son2 : public Base<T2> {
public:
    Son2() {
        cout << "T1的类型为: " << typeid(T1).name()
             << ", T2的类型为: " << typeid(T2).name() << endl;
    }

    T1 obj;
};

void test2() {
    Son2<int, char> s2;
}

int main() {
    test2();
    return 0;
}