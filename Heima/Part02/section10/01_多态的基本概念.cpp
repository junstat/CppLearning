#include <iostream>

using namespace std;

// 多态
class Animal {
public:
    // 虚函数
    virtual void speak() {
        cout << "动物在说话" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() {
        cout << "小猫在说话" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() {
        cout << "小狗在说话" << endl;
    }
};

// 执行说话的函数
// 地址早绑定 在编译阶段就确定了函数的地址
// 如果想执行让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定

// 动态多态满足条件:
// 1. 有继承关系
// 2. 子类要重写父类的虚函数

// 动态多态使用
// 父类的指针或者引用 指向子类对象
void doSpeak(Animal &animal) {
    animal.speak();
}

void test1() {
    Cat cat;
    Dog dog;
    doSpeak(cat);
    doSpeak(dog);
}

void test2() {
    // 非虚函数，Animal 1个字节, Cat 1个字节
    // 虚函数, Animal 8个字节，Cat 8个字节
    cout <<"sizeof Animal = "  << sizeof(Animal) << endl;
    cout <<"sizeof Cat = "  << sizeof(Cat) << endl;
}

int main() {
    test2();
    return 0;
}