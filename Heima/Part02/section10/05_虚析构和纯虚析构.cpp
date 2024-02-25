#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    Animal() {
        cout << "Animal()" << endl;
    }

    // 利用虚析构可以解决 父类指针释放子类对象时不干净的问题
    // virtual ~Animal() {
    //     cout << "~Animal()" << endl;
    // }

    // 纯虚析构 需要声明也需要实现
    // 有了纯虚析构之后，这个类也属于抽象类，无法实例化对象
    virtual ~Animal() = 0;

    virtual void speak() = 0;
};

Animal::~Animal() {
    cout << "Animal::~Animal()" << endl;
}

class Cat : public Animal {
public:
    Cat(string name) {
        cout << "Cat(name)" << endl;
        this->name = new string(name);
    }

    ~Cat() override {
        if (name != nullptr) {
            cout << "~Cat()" << endl;
            delete name;
            name = nullptr;
        }
    }

    virtual void speak() {
        cout << *name << ": Meow" << endl;
    }

    string *name;
};

void test1() {
    Animal *animal = new Cat("Tom");
    animal->speak(); // Output: Meow
    // 父类指针在析构时，不会调用子类中的析构函数，导致子类如果有堆区属性，会出现内存泄漏
    delete animal;
}

int main() {
    test1();
    return 0;
}