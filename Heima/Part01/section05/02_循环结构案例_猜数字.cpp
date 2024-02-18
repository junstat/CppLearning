#include <iostream>
#include <ctime>

using namespace std;

int main() {
    // 添加随机数种子，利用当前系统时间生成随机数
    // 防止每次随机数都一样
    srand(time(NULL));
    // 1. 系统生成随机数
    int num = rand() % 100 + 1;
    // cout << "系统生成的随机数是：" << num << endl;
    // 2. 玩家进行猜测
    int val = 0;

    while (1) {
        cin >> val;

        if (val > num) cout << "您猜大了...." << endl;
        else if (val < num)
            cout << "您猜小了...." << endl;
        else {
            cout << "恭喜您猜对了！" << endl;
            break;
        }
    }
    return 0;
}