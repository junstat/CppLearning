#include "../utils/print.h"

class SetCompare {
public:
    bool operator()(int a, int b) {
        return a > b;
    }
};


void test1() {
    set<int> s1 = {10, 40, 20, 50, 30};

    print<set<int>>(s1);

    // 指定排序规则为从大到小
    set<int, SetCompare> s2 = {10, 40, 20, 50, 30};
    print<set<int, SetCompare>>(s2);

}

int main() {
    test1();
    return 0;
}