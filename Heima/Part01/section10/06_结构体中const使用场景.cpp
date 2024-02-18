#include <iostream>
#include <string>

using namespace std;

// const的使用场景
struct Student {
    string name;
    int age;
    int score;
};

// 将函数中的形参改为指针，可以减少内存开销
void print(const Student *s) {
    // s->age = 200; // 加入const 之后， 一旦有修改操作就会报错，可以防止误操作
    cout << "姓名：" << s->name
         << " 年龄：" << s->age
         << " 成绩：" << s->score << endl;

}

int main() {
    // 创建结构体变量
    Student s = {"张山", 15, 70};
    print(&s);
    return 0;
}