#include <iostream>
#include <string>

using namespace std;

// 结构体指针
struct Student {
    string name;
    int age;
    int score;
};

int main() {
    Student s = {"张山", 18, 90};
    Student *p = &s;
    cout << "姓名: " << p->name
         << ", 年龄: " << p->age
         << ", 成绩: " << p->score << endl;
    // 结构体指针可以通过 -> 操作符 来访问结构体中的成员
    return 0;
}