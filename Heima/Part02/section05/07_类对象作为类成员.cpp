#include <iostream>
#include <string>

using namespace std;

// 类对象做为类成员
class Phone {
public:
    Phone(string brand) : brand(brand) {
        cout << "Phone构造函数" << endl;
    }

    ~Phone() {
        cout << "Phone析构函数" << endl;
    }

    string brand;

};

class Person {
public:
    // Phone phone = pName;  隐式转换
    Person(string name, string pName) : name(name), phone(pName) {
        cout << "Person构造函数" << endl;
    }

    ~Person() {
        cout << "Person析构函数" << endl;
    }

    string name;
    Phone phone;
};

// 当其他类对象作为类成员时，初始化顺序是：先初始化成员，再调用构造函数
// 析构顺序：先调用析构函数，再销毁成员
void test1() {
    Person p("张山", "华为");
    cout << p.name << "的手机品牌是：" << p.phone.brand << endl;
}

int main() {
    test1();
    return 0;
}