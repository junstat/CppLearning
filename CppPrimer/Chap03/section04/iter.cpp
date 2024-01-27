#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 标准容器迭代器的运算符
// *iter  // 返回迭代器iter所指元素的引用
// iter -> mem // 解引用iter并获取该元素的名为mem的成员，等价于(*iter).mem
// ++iter
// --iter
// iter1 == iter2
// iter1 != iter2

void test1() {
    string s("some string");
    if (s.begin() != s.end()) {
        auto it = s.begin();
        *it = toupper(*it);
    }
    cout << s << endl;
}

// 将迭代器从一个元素移动到另一个元素
void test2() {
    string s("some string");
    // 依次处理s的字符直至我们处理完全部自负或者遇到空白
    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
        *it = toupper(*it);
    cout << s << endl;
}

// begin 和 end运算符
// begin 和 end返回的具体类型由对象是否是常量决定，如果对象是常量
// begin 和 end返回const_iterator；如果对象不是常量，返回iterator
void test3() {
    vector<int> v;
    const vector<int> cv;
    auto it1 = v.begin();
    auto it2 = cv.begin();
    auto it3 = cv.begin();
}

// 结合解引用和成员访问操作
void test4() {
    string text("some string");
    for (auto it = text.cbegin();
         it != text.cend() && !isspace(*it);
         ++it)
        cout << *it << endl;
}

// vector和string迭代器支持的运算
// iter + n
// iter - n
// iter1 += n
// iter1 -= n
// iter1 - iter2
// >, >=, <, <=

// 使用迭代器运算
void test5() {
    string text("abcdefghijklmn");
    char sought = 'c';
    auto beg = text.begin(), end = text.end();
    auto mid = beg + (end - beg) / 2;
    while (mid != end && *mid != 'i') {
        if (sought < *mid)
            end = mid;
        else
            beg = mid + 1;
        mid = beg + (end - beg) / 2;
    }
    cout << *mid << endl;
}


int main() {
    test5();
    return 0;
}