#include <iostream>
#include <map>

using namespace std;

// erase有两种用法：删除单个元素、删除一个区间内的所有元素
// 删除单个元素有两种方法:
// mp.erase(it), it为需要删除的元素的迭代器
// mp.erase(key), key为需要删除的元素的键值
void erase_single_element(map<char, int> mp) {
    // 通过迭代器删除元素
    auto it = mp.find('b');
    mp.erase(it);

    // 通过键值删除元素
    mp.erase('c');

    for (const auto &item: mp)
        cout << item.first << " " << item.second << endl;
}

// mp.erase(first, last) 其中first为需要删除的区间的起始迭代器，last为需要删除的区间的末尾迭代器
void erase_range_iterator(map<char, int> mp) {
    auto it = mp.find('b');
    mp.erase(it, mp.end());
    for (const auto &item: mp)
        cout << item.first << " " << item.second << endl;

}

int main() {
    map<char, int> mp;
    mp['a'] = 1;
    mp['b'] = 2;
    mp['c'] = 3;

    erase_single_element(mp);

    erase_range_iterator(mp);
    return 0;
}