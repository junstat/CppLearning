#include <iostream>
#include <map>

using namespace std;

int main() {
    map<char, int> mp;
    mp['a'] = 1;
    mp['b'] = 2;
    mp['c'] = 3;
    auto it = mp.find('b');
    if (it != mp.end()) {
        printf("找到了键为b的元素，其值为%d\n", it->second);
    } else {
        printf("未找到键为b的元素\n");
    }
    return 0;
}