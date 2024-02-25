#include <iostream>
#include <vector>

using namespace std;

void test1() {
    vector<int> v;

    // 利用reserve预留空间
    v.reserve(100000);
    int num = 0;  // 统计开辟空间次数
    int *p = nullptr;
    for (int i = 0; i < 100000; ++i) {
        v.push_back(i);
        if (p != &v[0]) {
            p = &v[0];
            num++;
        }
    }
    cout << "vector共开辟了" << num << "次空间" << endl;
    cout << "vector的容量为" << v.capacity() << endl;
}

int main() {
    test1();
    return 0;
}