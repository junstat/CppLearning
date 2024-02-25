#include <iostream>

using namespace std;

// 1. 构造函数的分类及调用
// 分类
//     按照参数分类 无参构造(默认构造) 和 有参构造
//     按照类型分类 普通构造 和 拷贝构造
class Person {
public:
    Person() {
        cout << "Person的无参构造函数" << endl;
    }

    Person(int a) {
        cout << "Person的有参构造函数" << endl;
        age = a;
    }

    // 拷贝构造函数
    Person(const Person &p) {
        cout << "Person的拷贝构造函数" << endl;
        age = p.age;
    }

    ~Person() {
        cout << "Person的析构函数" << endl;
    }

    int age;
};

int main() {
    // 调用
    // 1. 括号法
    // Person p1;  // 默认构造函数调用
    // Person p2(10);
    // Person p3(p2);
    // cout << "p2的年龄为: " << p2.age << endl;
    // cout << "p3年龄为: " << p3.age << endl;

    // 注意事项
    // 调用默认构造函数时，不要加()
    // 因为下面这行代码，编译器会认为是一个函数的声明
    // Person p1();

    // 2. 显式法
    // Person p1;
    // Person p2 = Person(10);
    // Person p3 = Person(p2);
    // Person(10);  // 匿名对象
    // 当前行执行结束后，系统会立即回收掉匿名对象

    // 注意事项2
    // 不要利用拷贝构造函数 初始化匿名对象
    // 编译器会认为 Person(p3) <=> Person p3; 对象声明
    // Person(p3);

    // 3. 隐式转换法
    Person p4 = 10;  // 编译器会认为 Person p4 = Person(10);
    Person p5 = p4;
    return 0;
}