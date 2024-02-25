#include <iostream>

using namespace std;

class AbstractDrinking {
public:
    // 煮水
    virtual void boil() = 0;

    // 冲泡
    virtual void brew() = 0;

    // 倒入杯中
    virtual void pourInCup() = 0;

    // 加入辅料
    virtual void addCondiments() = 0;

    // 制作饮品
    void makeDrink() {
        boil();
        brew();
        pourInCup();
        addCondiments();
    }
};

// 制作咖啡
class Coffee : public AbstractDrinking {
public:
    void boil() {
        cout << "煮农夫山泉" << endl;
    }

    void brew() {
        cout << "用沸水冲泡咖啡" << endl;
    }

    void pourInCup() {
        cout << "将咖啡倒进杯子" << endl;
    }

    void addCondiments() {
        cout << "加糖和牛奶" << endl;
    }
};

// 制作茶
class Tea : public AbstractDrinking {
public:
    void boil() {
        cout << "煮矿泉水" << endl;
    }

    void brew() {
        cout << "用沸水浸泡茶叶" << endl;
    }

    void pourInCup() {
        cout << "将茶倒进杯子" << endl;
    }

    void addCondiments() {
        cout << "加柠檬" << endl;
    }
};

// 制作函数
void makeDrink(AbstractDrinking *drink) {
    drink->makeDrink();
    delete drink;
}

void test1() {
    AbstractDrinking *ad = new Coffee();
    makeDrink(ad);

    cout << "---------------" << endl;
    ad = new Tea();
    makeDrink(ad);
}

int main() {
    test1();
    return 0;
}