#include <iostream>
#include <string>

using namespace std;

class Building {
    friend class GoodGay;  // 友元类
public:
    Building() {
        sittingRoom = "客厅";
        bedRoom = "卧室";
    }

    string sittingRoom;
private:
    string bedRoom;
};

class GoodGay {
public:
    GoodGay() {
        building = new Building;
    }

    void visit() {  // 参观函数，访问Building 中的属性
        cout << "好基友在访问 public属性" << building->sittingRoom << endl;
        cout << "好基友在访问 private属性" << building->bedRoom << endl;
    }

    Building *building;
};

int main() {
    GoodGay goodGay;
    goodGay.visit();
    return 0;
}