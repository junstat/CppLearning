#include <iostream>

using namespace std;

struct Student {
    string name;
    int age;
    int score;
};

void print(Student s) {
    s.age = 100;
    cout << "2. " << s.name << " " << s.age << " " << s.score << endl;
}

void print(Student *s) {
    cout << "3. " << s->name << " " << s->age << " " << s->score << endl;
}

int main() {
    Student s = {"张山", 18, 90};
    cout << "1. " << s.name << " " << s.age << " " << s.score << endl;
    print(s);
    cout << "4. " << s.name << " " << s.age << " " << s.score << endl;
    print(&s);
    // 总结: 如果不想修改主函数中的数据，用值传递，反之用地址传递
    return 0;
}