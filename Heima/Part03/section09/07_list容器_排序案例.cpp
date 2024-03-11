#include <iostream>
#include <string>
#include <list>

using namespace std;

// list容器 排序案例 对于自定义数据类型 做排序

// 按照年龄进行升序，如果年龄相同则按照身高进行降序

class Person {
public:

    Person(string name, int age, int height) :
            name(name), age(age), height(height) {}

    string name;
    int age;
    int height;
};

void test1() {
    list<Person> lst;
    lst.emplace_back("刘备", 35, 175);
    lst.emplace_back("曹操", 45, 180);
    lst.emplace_back("孙权", 40, 170);
    lst.emplace_back("赵云", 25, 190);
    lst.emplace_back("张飞", 35, 160);
    lst.emplace_back("关羽", 35, 200);

    for (const auto &p: lst) {
        cout << "name: " << p.name << " age: " << p.age << " height: " << p.height << endl;
    }

    cout << "---------------------------------------" << endl;
    cout << "排序后: " << endl;

    lst.sort([](const Person &p1, const Person &p2) {
        return (p1.age == p2.age) ? (p1.height > p2.height) : (p1.age < p2.age);
    });

    for (const auto &p: lst) {
        cout << "name: " << p.name << " age: " << p.age << " height: " << p.height << endl;
    }
}

int main() {
    test1();
    return 0;
}