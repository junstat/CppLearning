#include "../utils/print.h"

void test1() {
    vector<int> v = {20, 30, 50, 30, 40, 20, 10, 20};

    cout << "替换前: " << endl;
    print(v);

    replace(v.begin(), v.end(), 20, 2000);
    cout << "替换后: " << endl;
    print(v);
}

int main() {
    test1();
    return 0;
}