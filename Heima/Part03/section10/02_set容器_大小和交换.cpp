#include "../utils/print.h"

void test1() {
    set<int> s1 = {10, 30, 20, 40};

    print<set<int>>(s1);
    if (s1.empty()) {
        cout << "set is empty" << endl;
    } else {
        cout << "set is not empty" << endl;
        cout << "size of set: " << s1.size() << endl;
    }


}

void test2() {
    set<int> s1 = {10, 30, 20, 40};
    set<int> s2 = {100, 300, 200, 400};

    cout << "交换前: " << endl;
    print<set<int>>(s1);
    print<set<int>>(s2);

    cout <<"交换后: " << endl;
    s1.swap(s2);
    print<set<int>>(s1);
    print<set<int>>(s2);

}

int main() {
    test2();
    return 0;
}