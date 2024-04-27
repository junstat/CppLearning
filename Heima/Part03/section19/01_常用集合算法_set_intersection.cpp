#include "../utils/print.h"

void test1() {
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
        v2.push_back(i + 5);
    }

    vector<int> dest;
    dest.resize(min(v1.size(), v2.size()));

    // 获取交集
    auto itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), dest.begin());

    print(dest);
}

int main() {
    test1();
    return 0;
}

