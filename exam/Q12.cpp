#include <map>
#include <iostream>

using namespace std;

class AlmProcessUnit {
};

int main() {
    map<int, AlmProcessUnit *> almUnitMap{{1, new AlmProcessUnit}};
    for (auto it: almUnitMap) {
        cout << typeid(it.second).name() << endl;
    }
    return 0;
}