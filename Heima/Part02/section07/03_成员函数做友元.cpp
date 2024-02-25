#include <iostream>
#include <string>

using namespace std;


class Building;

class GoodGay {
public:
    GoodGay();

    // 让visit函数可以访问Building中私有成员
    void visit();

    // 让visit2函数不可以访问Building中私有成员
    void visit2();

private:
    Building *building;
};


class Building {
    friend void GoodGay::visit();

public:
    Building();

    string sittingRoom;
private:
    string bedRoom;
};

Building::Building() {
    sittingRoom = "客厅";
    bedRoom = "卧室";
}

GoodGay::GoodGay() {
    building = new Building;
}

void GoodGay::visit() {
    cout << "visit函数正在访问: " << building->sittingRoom << endl;
    cout << "visit函数正在访问: " << building->bedRoom << endl;
}

void GoodGay::visit2() {
    cout << "visit2函数正在访问: " << building->sittingRoom << endl;
    // cout << "visit2函数正在访问: " << building->bedRoom << endl;
}

int main() {
    GoodGay gg;
    gg.visit();
    gg.visit2();
    return 0;
}