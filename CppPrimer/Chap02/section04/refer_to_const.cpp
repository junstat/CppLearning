// 2.4.1 const的引用
// 可以把引用绑定到const对象上，就像绑定到其他对象上一样
// 称之为对常量的引用(reference to const)
// 与普通引用不同的是，对常量的引用不能被用作修改它所绑定的对象
void test1() {
    const int ci = 1024;
    // const int & : reference to const 对常量的引用，
    // 只能引用 const int 类型
    const int &r1 = ci; // 正确: 引用及其对应的对象都是常量
    // r1 = 42; // 错误: r1是对常量的引用
    // int &r2 = ci;  // 错误: 试图让一个非常量引用指向一个常量对象
}

// 初始化和对const的引用
// 在初始化常量引用时运行用任意表达式作为初始值
// 只要该表达式的结果能转换成引用的类型即可
// 尤其允许为一个常量引用绑定非常量对象、字面值，甚至是个一般表达式
void test2() {
    int i = 42;
    const int &r1 = i; // 允许将const int& 绑定到一个普通int对象上
    const int &r2 = 42; // 正确: r2是一个常量引用
    const int &r3 = r1 * 2; // 正确: r3是一个常量引用
    // int &r4 = r1 * 2; // 错误: r4是一个非常量引用


    double dval = 3.14;
    // 如下是正确的
    // const int &ri = dval;

    // 等价于
    const int temp = dval; // 由双精度浮点数生成一个临时的整型常量
    const int &ri = temp; // 让ri绑定这个临时量
}

// 对const的引用可能引用一个并非const的对象
void test3() {
    int i = 42;
    int &r1 = i;  // 引用ri绑定对象i
    const int &r2 = i; // r2也绑定对象i，但是不允许通过r2修改i的值
    r1 = 0; // r1并非常量，i的值修改为0
    // r2 = 0; // 错误: r2是一个常量引用
}

int main() {
    test2();
    return 0;
}