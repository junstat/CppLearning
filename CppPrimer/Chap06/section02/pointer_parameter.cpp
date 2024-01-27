#include <iostream>

using namespace std;

// 指针形参
void test1() {
    int n = 0, i = 42;
    int *p = &n, *q = &i; // p指向n；q指向i
    *p = 42; // n的值改变；p不变
    p = q; // p现在指向了i；但是i和n的值
}

void reset(int *ip) {
    *ip = 0; // 改变指针ip所指对象的值
    ip = 0; // 只改变了ip的局部拷贝，实参未被改变
}

void test2() {
    int i = 42;
    reset(&i); // 改变i的值而非i的地址
    cout << " i = " << i << endl;
}

// 传引用参数
void reset(int &i) {
    i = 0; // 改变了i所引用对象的值
}

void test3() {
    int j = 42;
    reset(j); // j采用传引用方式，它的值被改变
    cout << " j = " << j << endl;
}

// 使用引用避免拷贝
bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

// 使用引用形参返回额外信息
string::size_type find_char(const string &s, char c,
                            string::size_type &occurs) {
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != ret; ++i) {
        if (s[i] == c) {
            if (ret == s.size())
                ret = i;
            ++occurs;
        }
    }
    return ret;
}

int main() {
    test3();
    return 0;
}