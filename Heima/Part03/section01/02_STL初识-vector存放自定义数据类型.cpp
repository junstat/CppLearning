#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Person {
public:
    Person(string name, int age) :
            name(name), age(age) {}

    string name;
    int age;
};

void test1() {
    vector<Person> persons = {
            {"Tom",   18},
            {"Jerry", 20},
            {"Mike",  22},
    };

    for (const auto &item: persons) {
        cout << item.name << " " << item.age << endl;
    }
}

// 存放自定义类型的指针
void test2() {
    vector<Person *> persons = {
            new Person("Tom", 18),
            new Person("Jerry", 20),
            new Person("Mike", 22),
    };

    for (const auto &item: persons) {
        cout << item->name << " " << item->age << endl;
    }
}


int main() {
    test2();
    return 0;
}