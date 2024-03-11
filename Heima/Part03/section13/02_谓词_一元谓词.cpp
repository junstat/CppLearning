#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 仿函数 返回值类型是bool数据类型，称为谓词
// 一元谓词

class GreaterFive {
public:
    bool operator()(int val) {
        return val > 5;
    }
};

void test1() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    auto it = find_if(v.begin(), v.end(), GreaterFive());
    if (it != v.end()) {
        cout << "找到第一个大于5的数：" << *it << endl;
    } else {
        cout << "没有找到" << endl;
    }
}

int main() {
    test1();
    return 0;
}