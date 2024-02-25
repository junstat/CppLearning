#include <iostream>

using namespace std;

// 立方体设计
// 1. 创建立方体
// 2. 设计属性
// 3. 获取立方体面积和体积
// 4. 分别利用全局函数和成员函数 判断两个立方体是否相等

class Cube {
public:
    Cube(int l, int w, int h) : l(l), w(w), h(h) {}

    int area() const { return 2 * (l * w + l * h + w * h); }

    int volume() const { return l * w * h; }

    bool operator==(const Cube &c) { return this->volume() == c.volume(); }

private:
    int l;
    int w;
    int h;
};

// 利用全局函数判断，两个立方体是否相等
bool equal(const Cube &c1, const Cube &c2) {
    return c1.volume() == c2.volume();
}

int main() {
    Cube c1(3, 4, 5);
    Cube c2(3, 4, 5);
    Cube c3(5, 6, 7);

    cout << "c1 area: " << c1.area() << endl;
    cout << "c1 volume: " << c1.volume() << endl;
    cout << "c1 == c2: " << (c1 == c2 ? "true" : "false") << endl;
    cout << "c1 == c3: " << (equal(c1, c3) ? "true" : "false") << endl;
    return 0;
}