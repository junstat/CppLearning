#include "../utils/print.h"

class Person {
public:
    Person(string name, int age) :
            name(name), age(age) {}

    void show() const {
        cout << "name: " << name << " age: " << age << endl;
    }

    string name;
    int age;
};

class ComparePerson {
public:
    bool operator()(const Person &p1, const Person &p2) {
        //按照年龄 降序
        return p1.age > p2.age;
    }

};

void test1() {
    set<Person, ComparePerson> s;
    s.emplace("刘备", 24);
    s.emplace("关羽", 28);
    s.emplace("张飞", 25);
    s.emplace("赵云", 21);

    for (const auto &item: s)
        item.show();
}

int main() {
    test1();
    return 0;
}