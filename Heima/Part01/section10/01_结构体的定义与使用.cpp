#include <iostream>
#include <string>

using namespace std;

// 1> 创建学生数据类型: 学生的属性: 姓名，年龄，分数
struct Student {
    string name;
    int age;
    int score;
};

int main() {
    Student s1;
    s1.name = "张山";
    s1.age = 18;
    s1.score = 90;
    cout << "姓名：" << s1.name << ", 年龄: " << s1.age << ", 成绩: " << s1.score << endl;

    Student s2 = {"李思", 19, 85};
    cout << "姓名：" << s2.name << ", 年龄: " << s2.age << ", 成绩: " << s2.score << endl;

    return 0;
}