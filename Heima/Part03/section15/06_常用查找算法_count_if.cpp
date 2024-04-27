#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 统计内置数据类型
class Greater20 {
public:
    bool operator()(int val) {
        return val > 20;
    }
};

void test1() {
    vector<int> v = {10, 40, 30, 20, 40, 20};
    auto num = count_if(v.begin(), v.end(), Greater20());
    cout << "大于20的元素个数为：" << num << endl;
}

class Person {
public:
    Person(string name, int age) :
            name(name), age(age) {}

    string name;
    int age;
};

class AgeGreater20 {
public:
    bool operator()(const Person &p) {
        return p.age > 20;
    }
};

// 统计自定义数据类型
void test2() {
    vector<Person> v = {
            Person("张三", 20),
            Person("李四", 30),
            Person("王五", 30),
            Person("赵六", 10),
            Person("田七", 50)
    };

    auto num = count_if(v.begin(), v.end(), AgeGreater20());
    cout << "年龄大于20的人数为：" << num << endl;
}

int main() {
    test2();
    return 0;
}
