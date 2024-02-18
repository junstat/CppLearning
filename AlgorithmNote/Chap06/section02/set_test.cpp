#include <iostream>
#include <set>

using namespace std;

// set的定义
// set内的元素自动递增排序，且自动去除了重复元素
void test1() {
    set<int> st;
    st.insert(3);
    st.insert(5);
    st.insert(2);
    st.insert(3);

    for (auto it = st.begin(); it != st.end(); it++)
        cout << *it << " ";
}

// 2. set常用函数实例解析
// insert(x) 将x插入Set容器中，并自动递增排序和去重，时间复杂度为O(log N)
// find(value) 返回set中对应值为value的迭代器，时间复杂度为O(log N)
void test2() {
    set<int> st;
    for (int i = 1; i <= 3; i++)
        st.insert(i);

    auto it = st.find(2);
    cout << "*it = " << *it << endl;
    auto it1 = st.find(5);
    cout << "*it1 = " << *it1 << endl;
}

// 3.
// - erase(it) it为所需删除的迭代器，时间复杂度为O(1)
// - erase(value) value所需要删除元素的值。时间复杂度为O(log N)
void test3() {
    set<int> st;
    st.insert(100);
    st.insert(200);
    st.insert(100);
    st.insert(300);
    st.insert(400);
    st.erase(st.find(100));
    st.erase(st.find(200));
    st.erase(400); // 删除set中值为400的元素
    for (const auto &item: st)
        cout << item << " ";
    cout << endl;
}

// - erase(first, last) 可以删除一个区间内的所有元素，删除区间[first, last)
// 时间复杂度为O(last-first)
void test4() {
    set<int> st;
    st.insert(10);
    st.insert(20);
    st.insert(10);
    st.insert(30);
    st.insert(40);
    st.erase(st.find(30), st.end());
    for (const auto &item: st)
        cout << item << " ";
    cout << endl;
}

// 4. size() 用来获取set内元素的个数，时间复杂度为O(1)

// 5. clear() 用来清空set中的所有元素，复杂度为O(N)

int main() {
    test4();
    return 0;
}
