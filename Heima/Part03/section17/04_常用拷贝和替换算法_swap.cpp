#include "../utils/print.h"

void test1() {
    vector<int> v1;
    vector<int> v2;

    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
        v2.push_back(i + 100);
    }

    cout << "交换前: " << endl;
    cout << "v1: ";
    print(v1);
    cout << "v2: ";
    print(v2);

    cout << "----------------------------------------------" << endl;

    swap(v1, v2);
    cout << "交换后: " << endl;
    cout << "v1: ";
    print(v1);
    cout << "v2: ";
    print(v2);
}

int main() {
    test1();
    return 0;
}