#include "../utils/print.h"

class MyCompare {
public:
    bool operator()(int a, int b) {
        return a > b;
    }
};

void test1() {
    map<int, int, MyCompare> mp = {
            {1, 10},
            {2, 20},
            {5, 50},
            {3, 30},
            {4, 40}
    };

    for (const auto &it: mp) {
        cout << "key = " << it.first <<
             ", value = " << it.second << endl;
    }
}

int main() {
    test1();
    return 0;
}