#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Person {
public:
    Person(string name, int age) : name(name), age(age) {}

    string name;
    int age;
};

int main() {
    // 创建队列
    queue<Person> q;
    // 准备数据
    q.emplace("Alice", 20);
    q.emplace("Bob", 25);
    q.emplace("Charlie", 30);
    q.emplace("David", 35);

    cout << "队列中的元素个数是：" << q.size() << endl;

    // 只要队列不为空，查看队头，查看队尾，出队
    while (!q.empty()) {
        cout << "队头元素 -- 姓名: " << q.front().name << " 年龄:" << q.front().age << endl;
        cout << "队尾元素 -- 姓名: " << q.back().name << " 年龄:" << q.back().age << endl;
        q.pop();
        cout << "---------------------------------" << endl;
    }
    cout << "队列中的元素个数是：" << q.size() << endl;
    return 0;
}