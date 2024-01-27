#include <iostream>

using namespace std;

int main() {
    double obj = 3.14, *pd = &obj;
    /*
     * 利用void*指针能做的事儿比较有限: 拿它和别的指针比较、
     * 作为函数的输入或输出，或者赋给另外一个void*指针。
     * 不能直接操作void*指针所指的对象，因为编译器不知道对象是什么类型。
     * 也就无法确定能在这个对象上做哪些操作。
     */
    void *pv = &obj;
    pv = pd;
    return 0;
}