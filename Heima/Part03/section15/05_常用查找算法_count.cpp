#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 1. 统计内置数据类型
void test1() {
    vector<int> v = {10, 40, 30, 40, 20, 40};
    auto num = count(v.begin(), v.end(), 40);
    cout << "40的元素个数: " << num << endl;
}

// 2. 统计自定义数据类型
class Person {
public:
    Person(string name, int age) : name(name), age(age) {}

    bool operator==(const Person &p) const {
        return this->age == p.age;
    }

    string name;
    int age;
};

void test2() {
    vector<Person> v = {
            Person("Tom", 35),
            Person("Jack", 35),
            Person("Mike", 35),
            Person("Tom", 30),
            Person("Jack", 40)
    };

    Person p("Jun", 35);
    auto num = count(v.begin(), v.end(), p);
    cout << "和Jun同岁的人数为: " << num << endl;
}

int main() {
    test2();
    return 0;
}