#include <iostream>

using namespace std;

const double PI = 3.14;
// 设计一个圆类，求圆的周长
// 圆的周长公式: 2 * PI * 半径

class Circle {
    // 访问权限
    // public: 公共权限，可以在任何地方被访问
    // private: 私有权限，只能在类内部被访问
public:
    Circle(double r) : radius(r) {}

    double perimeter() {
        return 2 * PI * radius;
    }

private:
    double radius;
};

int main() {
    Circle c(10.0);
    cout << "圆的周长为：" << c.perimeter() << endl;
    return 0;
}