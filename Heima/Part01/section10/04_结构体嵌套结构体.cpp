#include <iostream>
#include <string>

using namespace std;

// 定义学生结构体
struct Student {
    string name;
    int age;
    int score;
};

// 定义老师结构体
struct Teacher {
    int id;
    string name;
    int age;
    Student stu;
};

int main() {
    Teacher t;
    t.id = 1001;
    t.name = "老王";
    t.age = 50;
    t.stu.name = "张山";
    t.stu.age = 18;
    t.stu.score = 90;
    cout << "老师的ID: " << t.id
         << ", 老师的姓名: " << t.name
         << ", 老师的年龄: " << t.age
         << "\n学生的姓名: " << t.stu.name
         << ", 学生的年龄: " << t.stu.age
         << ", 学生的成绩: " << t.stu.score << endl;
    return 0;
}