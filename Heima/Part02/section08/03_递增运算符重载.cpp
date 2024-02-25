#include <iostream>

using namespace std;

// 前置递增返回引用，后置递增返回值
class MyInteger {
    friend ostream &operator<<(ostream &cout, MyInteger myInt);

public:
    MyInteger(int num = 0) : num(num) {}

    // 重载前置++ 返回引用是为了一直对一个数据进行递增操作
    MyInteger &operator++() {
        ++num;
        return *this;
    }

    // 后置++
    // operator++(int) int代表占位参数，可以用于区分前置和后置递增
    MyInteger operator++(int) {
        // 先记录当时结果
        int ans = num;
        // 后递增
        ++num;
        return ans;
    }

private:
    int num;
};

ostream &operator<<(ostream &cout, MyInteger myInt) {
    cout << myInt.num;
    return cout;
}

void test1() {
    MyInteger n;
    cout << ++(++n) << endl;
}

void test2() {
    MyInteger n;
    cout << n++ << endl;
    cout << n << endl;
}

int main() {
    test2();
    // int a = 0;
    // cout << ++(++a) << endl;
    return 0;
}