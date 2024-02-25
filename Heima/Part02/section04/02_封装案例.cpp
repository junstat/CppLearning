#include <iostream>
#include <string>

using namespace std;

// 设计一个学生类，属性有姓名和学号
// 可以给姓名和学号赋值，可以显示学生的姓名和学号
class Student {
public:
    Student(string name, string id) : name(name), id(id) {}

    void setName(string name) {
        this->name = name;
    }

    void setId(string id) {
        this->id = id;
    }

    string getName() const {
        return name;
    }

    string getId() const {
        return id;
    }

    void show() {
        cout << "Name: " << name << ", ID: " << id << endl;
    }

private:
    string name;
    string id;
};

int main() {
    Student s("Jun", "2021001");
    s.show();
    return 0;
}