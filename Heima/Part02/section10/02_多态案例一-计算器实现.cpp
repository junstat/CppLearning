#include <iostream>
#include <string>

using namespace std;

// 分别利用普通写法和多态技术实现计算器

// 普通写法
class Calculator {
public:
    Calculator(int a, int b) : num1(a), num2(b) {}

    int getResult(string oper) {
        if (oper == "+") {
            return num1 + num2;
        } else if (oper == "-") {
            return num1 - num2;
        } else if (oper == "*") {
            return num1 * num2;
        } else if (oper == "/") {
            return num1 / num2;
        } else {
            return 0;
        }
        // 如果想扩展新的功能，需要修改源代码，违反开闭原则
        // 开闭原则: 对扩展进行开发，对修改进行关闭
    }

    int num1;
    int num2;
};

// 利用多态技术实现计算器
// 多态好处:
// 1. 组织结构清晰
// 2. 可读性强
// 3. 对于前期和后期扩展以及维护性高
// 实现计算器抽象类
class AbstractCalculator {
public:
    virtual int getResult() {
        return 0;
    }

    int num1;
    int num2;
};

// 加法计算器
class AddCalculator : public AbstractCalculator {
public:
    int getResult() {
        return num1 + num2;
    }
};

// 减法计算机器
class SubCalculator : public AbstractCalculator {
public:
    int getResult() {
        return num1 - num2;
    }
};

// 实现乘法计算器
class MulCalculator : public AbstractCalculator {
public:
    int getResult() {
        return num1 * num2;
    }
};

// 实现除法计算器
class DivCalculator : public AbstractCalculator {
public:
    int getResult() {
        return num1 / num2;
    }
};

void test1() {
    Calculator c(10, 10);
    cout << "10 + 10 = " << c.getResult("+") << endl;
    cout << "10 - 10 = " << c.getResult("-") << endl;
    cout << "10 * 10 = " << c.getResult("*") << endl;
    cout << "10 / 10 = " << c.getResult("/") << endl;
}

void test2() {
    // 利用多态技术实现计算器
    AbstractCalculator *c1 = new AddCalculator();
    c1->num1 = 10;
    c1->num2 = 10;
    cout << "10 + 10 = " << c1->getResult() << endl;
    delete c1;

    c1 = new SubCalculator();
    c1->num1 = 10;
    c1->num2 = 10;
    cout << "10 - 10 = " << c1->getResult() << endl;
}

int main() {
    test2();
    return 0;
}