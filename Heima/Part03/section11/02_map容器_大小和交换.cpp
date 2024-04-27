#include "../utils/print.h"

void test1() {
    map<int, int> mp = {
            {1, 10},
            {2, 20},
            {3, 30}
    };

    if (mp.empty()) {
        cout << "map is empty" << endl;
    } else {
        cout << "map is not empty" << endl;
        cout << "map size is " << mp.size() << endl;
    }
}

void test2() {
    map<int, int> mp = {
            {1, 10},
            {2, 20},
            {3, 30}
    };
    map<int, int> mp2 = {
            {4, 100},
            {5, 200},
            {6, 300}
    };

    cout << "交换前: " << endl;
    print<int, int>(mp);
    print<int, int>(mp2);
    mp.swap(mp2);
    cout << "交换后: " << endl;
    print<int, int>(mp);
    print<int, int>(mp2);

}

int main() {
    test2();
    return 0;
}