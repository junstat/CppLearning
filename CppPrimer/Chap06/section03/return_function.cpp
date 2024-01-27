#include <iostream>
#include <string>

using namespace std;

// 有返回值的函数
// 值是如何被返回的

// 如果ctr的值大于1，返回word的复数形式
string make_plural(size_t ctr, const string &word,
                   const string &ending) {
    return (ctr > 1) ? word + ending : word;
}
// 该函数的返回类型是string，意味着返回值将被拷贝到调用点。
// 因此，该函数将返回word的副本或者一个未命名的临时string对象

// 同其他引用类型一样，如果函数返回引用，则该引用仅是它所引对象的一个别名
const string &shorterString(const string &s1, const string &s2) {
    return s1.size() <= s2.size() ? s1 : s2;
}

// 不要返回局部对象的引用或指针
// 严重错误: 这个函数试图返回局部对象的引用
// const string &manip() {
//     string ret;
//     以某种方式改变一下 ret
// if (!ret.empty()) return ret; // 错误: 返回局部对象的引用!
// else return "Empty"; // 错误: "Empty"是一个局部临时量
// }
// 要想确保返回值安全，我们不妨提问: 引用所引的是在函数之前已经存在
// 的哪个对象?

// 返回类类型的函数和调用运算符
// 调用运算符也有优先级和结合率，调用运算符的优先级
// 与点运算符和箭头运算符相同，并且也符合左结合律
// 因此，如果函数返回指针、引用或类的对象，
// 就能使用函数调用的结果访问结果对象的成员

// 调用string对象的size成员，该string对象是由shorterString函数返回的
auto sz = shorterString("Hello", "World").size();


// 引用返回左值
// 函数的返回类型决定函数调用是否是左值。调用一个引用的函数得到左值，
// 其他返回类型得到右值。可以像其他左值那样来使用返回引用的函数的调用
// 特别是，我们能为返回类型是非常量引用的函数的结果赋值
char &get_val(string &str, string::size_type ix) {
    return str[ix]; // get_val假定索引值是有效的
}

void test1() {
    string s("a value");
    cout << s << endl;  // 输出a value
    get_val(s, 0) = 'A'; // 将s[0]的值改为A
    // 把函数调用放在赋值语句的左侧可能看起来有点奇怪
    // 返回值是引用，因此调用是个左值，和其他左值一样
    // 它也能出现在赋值运算符的左侧
    cout << s << endl;  // 输出A value
}

// 返回数组的指针
// 因为数组不能被拷贝面，所以函数不能返回数组。
// 不过，函数可以返回数组的指针或引用。
// 虽然从语法上来说，要想定义一个返回数组的指针
// 或引用的函数比较繁琐，但是有一些方法可以简化这一任务
// 其中最直接的方法是使用通类型别名
// typedef int arrT[10];  // arrT是一个类型别名，它表示的类型是含有10个int的数组
// using arrT = int[10];  // arrT的等价声明
// arrT *func(int i); // func返回一个指向含有10个整数的数组指针

// 声明一个返回数组指针的函数
// 要想在声明func时不使用类型别名，必须牢记被定义的名字后面数组的维度
int arr[10];  // arr是一个含有10个整数的数组
int *p1[10];  // p1是一个含有10个指针的数组
int(*p2)[10];  // p2是一个指针，它指向含有10个整数的数组

// 和这些声明一样，如果我们想定义一个返回数组指针的函数，则数组的维度必须
// 跟在函数名字之后。然而，函数的形参列表也跟在函数名字后面且形参列表应该先
// 于数组的维度
// 因此，返回数组指针的函数形式如下所示:
// Type (*function(parameter_list))[dimension]
// 具体点的例子
// int (*func(int i))[10];
// 可以按以下的顺序来逐层理解该声明的含义:
// func(int i) 表示掉孙func函数时需要一个int类型的参数
// (*func(int i)) 意味着我们可以对函数调用的结果执行解引用操作
// int (*func(int i)) [10] 表示数组中的元素是int类型

// 使用尾置返回类型 (trailing return type)
// 尾置返回类型跟在形参列表后面并以一个 -> 符号开头。
// 为了表示函数真正的返回类型跟在形参列表之后，
// 在本应该出现返回类型的地方放置一个auto
// func 接受一个int类型的实参，返回一个指针，该指针指向含有10个整数的数组
auto func(int i) -> int (*)[10];

// 使用decltype
// 还有一种情况，如果知道函数返回的指针指向哪个数组，
// 就可以使用decltype关键字声明返回类型。
int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

// 返回一个指针，该指针指向含有5个整数的数组
decltype(odd) *arrPtr(int i) {
    return (i % 2) ? &odd : &even;
}


int main() {

    return 0;
}