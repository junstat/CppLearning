#include "../utils/print.h"

class Greater30 {
public:
    bool operator()(int val) {
        return val >= 30;
    }
};

void test1() {
    vector<int> v = {10, 40, 20, 40, 30, 50, 20, 30};
    cout << "替换前: " << endl;
    print(v);

    // 将大于等于30 替换为 3000
    replace_if(v.begin(), v.end(), Greater30(), 3000);

    cout << "替换后: " << endl;
    print(v);
}

int main() {
    test1();
    return 0;
}