#include <iostream>

using namespace std;

// 数组形参
// 数组的两个特殊性质对定义和使用作用在数组上的函数有影响。
// 这两个性质分别是: 不允许拷贝数组以及使用数组时(通常)会将其
// 转换成指针。
// 因为不能拷贝数组，所以无法以值传递的方式使用数组参数。
// 因为数组会被转换成指针，所以当为函数传递一个数组时，
// 实际上传递的是指向数组首元素的指针

// 因为数组是以指针的形式传递给函数的，所以一开始函数并不知道数组的确切尺寸
// 调用者应该为此提供一些额外的信息。
// 管理指针形参有三种常用的技术

// 1> 使用标记指定数组长度
// 管理数组实参的第一种方法是要求数组本身包含一个结束标记
// 使用这种方法的典型示例是C风格字符串
void print(const char *cp) {
    if (cp) // 若cp不是一个空指针
        while (*cp) // 只要指针所指的字符不是空字符
            cout << *cp++; // 输出当前字符并将指针向前移动一个位置
}

// 2> 使用标准库规范
// 传递指向数组首元素和尾后元素的指针
void print(const int *beg, const int *end) {
    // 输出beg到end之间(不含end)的所有元素
    while (beg != end)
        cout << *beg++ << endl;  // 输出当前元素并将指针向前移动一个位置
}

void test1() {
    int j[2] = {0, 1};
    print(begin(j), end(j));
}

// 3> 显式传递一个表示数组大小的形参
void print(const int ia[], size_t size) {
    for (size_t i = 0; i != size; ++i) {
        cout << ia[i] << endl;
    }
}

void test2() {
    int j[] = {0, 1};
    print(j, end(j) - begin(j));
}


// 数组引用形参
// C++语言允许将变量定义成数组的引用，基于同样的道理，
// 形参也可以是数组的引用。此时，引用形参绑定到对应的实参上
// 也就是绑定到数组上
// &arr两端的括号必不可少
// f(int &arr[10]) // 错误: 将arr声明成了引用的数组
void print(int (&arr)[10]) {
    for (auto elem: arr)
        cout << elem << endl;
}

void test3() {
    int i = 0, j[2] = {0, 1};
    int k[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // print(&i); // 错误: 实参不是含有10个整数的数组
    // print(j);  // 错位: 实参不是含有10个整数的数组
    print(k); // 正确: 实参是含有10个整数的数组
}

// 传递多维数组
void print(int (*matrix)[10], int rowsize) {
// matrix指向数组的首元素，该数组的元素是由10个整数构成的数组
// *matrix 两端的括号必不可少
// int *matrix[10];  // 10个指针构成的数组
// int (*matrix)[10];  // 指向含有10个整数的数组的指针
}

// 等价定义
// void print(int matrix[][10], int rowsize) {}

// 含有可变形参的函数
// initializer_list 形参
// initializer_list<T> lst;  // 默认初始化；T类型元素的空列表
// initializer_list<T> lst{a,b,c}; // lst的元素数量和初始值一样多；
// lst的元素是对应初始值的副本；列表中的元素是const

// 拷贝或赋值一个initializer_list对象不会拷贝列表中的元素；
// 拷贝后，原始列表和副本共享元素
// lst2(lst)
// lst2 = lst

// lst.size()  // 列表中的元素数量
// lst.begin()  // 返回指向lst中首元素的指针
// lst.end() // 返回指向lst中尾元素下一位置的指针

// initializer_list对象中的元素永远是常量值，无法修改
void error_msg(initializer_list<string> il) {
    for (auto beg = il.begin(); beg != il.end(); ++beg)
        cout << *beg << " ";
    cout << endl;
}

int main() {
    test3();
    return 0;
}