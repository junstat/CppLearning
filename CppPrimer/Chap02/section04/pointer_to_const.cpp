int main() {

    return 0;
}

// 常量指针(pointer to const)必须初始化
// 而且一旦初始化完成，则它的值(也就是存放在指针中的那个地址)就不能再改变了
// 把*放在const关键字之前可以说明指针是一个常量
// 隐含: 不变的是指针本身的值而非指向的那个值
void test2() {
    int errNumb = 0;
    int *const curErr = &errNumb; // curErr将一直指向errNumb
    const double pi = 3.14159;
    const double *const pip = &pi; // pip是一个指向常量对象的常量指针
}
// 要想弄清楚这些声明的含义最行之有效的办法是从右向左阅读
// 此例中，离curErr最近的符号是const，意味着curErr本身是一个常量对象
// 对象的类型由声明的其余部分确定。声明符号中的下一个符号是*，
// 意思是curErr是一个常量指针。
// 最后，该声明语句的基本数据类型部分确定了常量指针指向的是一个int对象。
// 与之相似，我们也能推断出，pip是一个常量指针


// 指向常量的指针(pointer to const) 不能用于改变其所指对象的值
// 要想存放常量对象的地址，只能使用指向常量的指针
void test1() {
    const double pi = 3.14; // pi是个常量，它的值不能改变
    // double *ptr = &pi; // 错误: ptr是一个普通指针
    const double *cptr = &pi; // 正确: cptr可以指向一个双精度常量
    // *cptr = 42; // 错误: 不能给*cptr赋值
}