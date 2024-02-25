#include <iostream>
#include <string>

using namespace std;

// 成员属性设置私有
// 1. 可以自己控制读写权限
// 2. 对于写可以检测数据有效性
class Person {
public:
    // 设置name为可读可写，age为只读，idol为只写
    string getName() { return name; }

    void setName(string n) { name = n; }

    int getAge() { return age; }

    void setAge(int a) {
        if (a < 0 || a > 150) {
            cout << "年龄输入有误，赋值失败" << endl;
            return;
        }
        age = a;
    }

    void setIdol(string i) { idol = i; }

private:
    string name; // 可读可写
    int age = 18; // 只读 也可以写(年龄必须在 0 到 150之间)
    string idol; // 只写
};

int main() {
    Person p;
    p.setName("张山");
    cout << "name = " << p.getName() << endl;
    cout << "age = " << p.getAge() << endl;
    p.setIdol("迪丽热巴");
    p.setAge(155);
    // cout << "idol = " << p.idol << endl; // 只写，访问不到
    return 0;
}