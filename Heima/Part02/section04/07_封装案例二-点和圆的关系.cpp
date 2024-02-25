#include <iostream>

using namespace std;

// 点和圆关系案例

// 点类
class Point {
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    int getX() { return x; }

    int getY() { return y; }

private:
    int x;
    int y;
};

// 圆类
class Circle {
public:
    Circle(int x = 0, int y = 0, int r = 0) : c(x, y), r(r) {}

    int getR() { return r; }

    Point getCenter() { return c; }

private:
    int r; // 半径
    Point c; // 圆心
};

// 判断点和圆的关系
void isInCircle(Circle &c, Point &p) {
    // 计算两点之间距离 平方
    int distance = (p.getX() - c.getCenter().getX()) * (p.getX() - c.getCenter().getX()) +
                   (p.getY() - c.getCenter().getY()) * (p.getY() - c.getCenter().getY());

    // 计算半径的平方
    int rSquare = c.getR() * c.getR();

    // 判断关系
    if (distance == rSquare) {
        cout << "点(" << p.getX() << ", " << p.getY() << ")在圆上" << endl;
    } else if (distance < rSquare) {
        cout << "点(" << p.getX() << ", " << p.getY() << ")在圆内" << endl;
    } else {
        cout << "点(" << p.getX() << ", " << p.getY() << ")在圆外" << endl;
    }
}

int main() {
    // 创建圆

    Circle c(10, 0, 10);

    // 创建点
    Point p1(10, 10);
    Point p2(10, 11);
    Point p3(10, 9);

    // 判断点和圆的关系
    isInCircle(c, p1);
    isInCircle(c, p2);
    isInCircle(c, p3);
    return 0;
}