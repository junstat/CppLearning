#include <iostream>

using namespace std;

// const形参和实参
// 当形参是const时，必须注意顶层const
// 顶层const作用于对象本身
void test1() {
    const int ci = 42; // 不能改变ci，const是顶层的
    int i = ci; // 正确: 当拷贝ci时，会忽略了它的顶层const
    int *const p = &i; // const是顶层的，不能给p赋值
    *p = 0; // 正确: 通过p改变对象的内容是允许的，现在i变成了0
}

// 和其他初始化过程一样，当用实参初始化形参时会忽略掉顶层const。
// 形参的顶层const被忽略了。当形参有顶层const时，
// 传给它常量对象或者飞常量对象都是可以的
void fcn(const int i) {
    // fcn能够读取i，但是不能向i写值
}

// 指针或引用形参与const
// 可以使用非常量初始化一个底层const对象，但是反过来不行；
// 同时一个普通的引用必须用同类型的对象初始化
void test2() {
    int i = 42;
    const int *cp = &i; // 正确: 但是cp不能改变i
    const int &r = i; // 正确: 但是r不能改变i
    const int &r2 = 42; // 正确
    // int *p = cp; // 错误：p的类型和cp的类型不匹配
    // int &r3 = r; // 错误: r3的类型和r的类型不匹配
    // int &r4 = 42; // 错误: 不能用字面值初始化一个非常量引用
}

void reset(int *ip) {
    *ip = 0; // 改变指针ip所指对象的值
    ip = 0; // 只改变了ip的局部拷贝，实参未被改变
}

void reset(int &i) {
    i = 0; // 改变了i所引用对象的值
}

string::size_type find_char(const string &s, char c,
                            string::size_type &occurs) {
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != ret; ++i) {
        if (s[i] == c) {
            if (ret == s.size())
                ret = i;
            ++occurs;
        }
    }
    return ret;
}


// 将同样的初始化规则应用到参数传递上可得如下形式:
void test3() {
    int i = 0;
    const int ci = i;
    string::size_type ctr = 0;
    reset(&i); // 调用形参类型是int*的reset函数
    // reset(&ci); // 错误: 不能用指向const int 对象的指针初始化int*
    reset(i); // 调用形参类型是int&的reset函数
    // reset(ci); // 错误: 不能把普通引用绑定到const对象ci上
    // reset(42);  // 错误: 不能把普通应用绑定到字面值上
    // reset(ctr); // 错误: 类型不匹配，ctr是无符号类型

    // 正确: find_char的第一个形参是对常量的引用
    find_char("Hello World!", 'o', ctr);
}

// 尽量使用常量引用
// 把函数不会改变的形参定义成(普通的)引用是一种比较常见的错误，
// 这么做带给函数的调用者一种误导，即函数可以修改它的实参的值
// 此外，使用引用而非常量引用也会极大地限制函数所能接受的实参类型


int main() {

    return 0;
}