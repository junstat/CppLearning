#include "../utils/print.h"

void test1() {
    vector<int> v = {10, 30, 50, 20, 40};
    cout << "反转前: " << endl;
    print(v);

    reverse(v.begin(), v.end());

    cout << "反转后: " << endl;
    print(v);
}

int main() {
    test1();
    return 0;
}