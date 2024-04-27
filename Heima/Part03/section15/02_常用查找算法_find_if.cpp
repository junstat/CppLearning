#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 1. 查找内置数据类型
class GreaterFive {
public:
    bool operator()(int val) {
        return val > 5;
    }
};

void test1() {
    vector<int> v;
    for (int i = 0; i < 10; ++i)
        v.push_back(i);

    auto it = find_if(v.begin(), v.end(), GreaterFive());
    if (it == v.end()) {
        cout << "没有找到!" << endl;
    } else {
        cout << "找到第一个大于5的元素: " << *it << endl;
    }
}

// 2. 查找自定义数据类型
class Person {
public:
    Person(string name, int age) : name(name), age(age) {}

    string name;
    int age;
};


class Greater20 {
public:
    bool operator()(Person &p) {
        return p.age > 20;
    }
};

void test2() {
    vector<Person> v;
    v.push_back(Person("Tom", 25));
    v.push_back(Person("Mike", 20));
    v.push_back(Person("Alice", 19));

    auto it = find_if(v.begin(), v.end(), Greater20());
    if (it == v.end()) {
        cout << "没有找到!" << endl;
    } else {
        cout << "找到第一个年龄大于20的人: " << it->name << " " << it->age << endl;
    }
}

int main() {
    test2();
    return 0;
}