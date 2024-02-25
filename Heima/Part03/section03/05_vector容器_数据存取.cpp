#include <iostream>
#include <vector>

using namespace std;

void test1() {
    vector<int> v1;
    for (int i = 0; i < 10; ++i)
        v1.push_back(i);

    for (int i = 0; i < v1.size(); ++i)
        // cout << v1[i] << " ";
        cout << v1.at(i) << " ";
    cout << endl;

    // 获取第一个元素
    cout << "第一个元素是：" << v1.front() << endl;
    // 获取最后一个元素
    cout << "最后一个元素是：" << v1.back() << endl;
}

int main() {
    test1();
    return 0;
}