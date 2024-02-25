#include <iostream>
#include <string>

using namespace std;

class Building {
    // 告诉编译器 goodGay全局函数是Building类的好朋友，可以访问其私有属性
    friend void goodGay(Building *building);

public:
    Building() {
        sittingRoom = "客厅";
        bedRoom = "卧室";
    }

    string sittingRoom;
private:
    string bedRoom;
};

void goodGay(Building *building) {
    cout << "好基友全局函数调用了 Building 的 公有属性: " << building->sittingRoom << endl;
    cout << "好基友全局函数调用了 Building 的 私有属性: " << building->bedRoom << endl;
}

void test1() {
    Building building;
    goodGay(&building);
}

int main() {
    test1();
    return 0;
}