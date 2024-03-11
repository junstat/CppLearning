#include <iostream>

using namespace std;

//函数对象 （仿函数）
/*
- 函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
- 函数对象超出普通函数的概念，函数对象可以有自己的状态
- 函数对象可以作为参数传递
*/

class MyAdd {
public:
    int operator()(int v1, int v2) {
        return v1 + v2;
    }
};

// 1、函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
void test1() {
    MyAdd myAdd;
    cout << myAdd(10, 10) << endl;
}

// 2、函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint {
public:
    MyPrint() : count(0) {}

    void operator()(string test) {
        cout << test << endl;
        count++;
    }

    int count;
};

void test2() {
    MyPrint myPrint;
    myPrint("hi.....");
    myPrint("hi.....");
    myPrint("hi.....");
    myPrint("hi.....");

    cout << "myPrint.count = " << myPrint.count << endl;
}

// 3、函数对象可以作为参数传递
void doPrint(MyPrint &mp, string test) {
    mp(test);
}

void test3() {
    MyPrint myPrint;
    doPrint(myPrint, "hi, cpp...");
}

int main() {
    test3();
    return 0;
}