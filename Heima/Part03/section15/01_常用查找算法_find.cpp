#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void test1() {
    vector<int> v;
    for (int i = 0; i < 10; ++i)
        v.push_back(i);

    // 查找是否有5
    auto it = find(v.begin(), v.end(), 5);
    if (it == v.end()) {
        cout << "没有找到!" << endl;
    } else {
        cout << "找到: " << *it << endl;
    }
}

class Person {
public:
    Person(string name, int age) : name(name), age(age) {}

    // 重载 == 底层find知道如何对比person数据类型
    bool operator==(const Person &p) const {
        return name == p.name && age == p.age;
    }

    string name;
    int age;
};

// 查找 自定义数据类型
void test2() {
    vector<Person> v = {
            {"aaa", 10},
            {"bbb", 20},
            {"ccc", 30},
            {"ddd", 40}
    };

    Person key("bbb", 20);
    auto it = find(v.begin(), v.end(), key);
    if (it == v.end()) {
        cout << "没有找到!" << endl;
    }
    else {
        cout << "找到: " << it->name << " " << it->age << endl;
    }
}

int main() {
    test2();
    return 0;
}