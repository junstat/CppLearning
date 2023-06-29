#include <list>
#include <string>
#include <vector>
#include <deque>
#include <array>
#include <forward_list>
#include <iostream>
#include "../../lib/Sales_data.h"

using namespace std;

void test1() {
    list<string> a = {"Milton", "Shakespeare", "Austen"};
    auto it1 = a.begin();
    auto it2 = a.rbegin();
    auto it3 = a.cbegin();
    auto it4 = a.crbegin();

    // 显式指定
    list<string>::iterator it5 = a.begin();
    list<string>::const_iterator it6 = a.begin();
    // 是iterator 还是const_iterator 依赖于a的类型
    auto it7 = a.begin();   // 仅当a是const时，it7是const_iterator
    auto it8 = a.cbegin();  // it8 是const_iterator
}

// 将一个容器初始化为另一个容器的拷贝
void test2() {
    // 每个容器有三个元素，用给定的初始化容器进行初始化
    list<string> authors = {"Milton", "Shakespeare", "Austen"};
    vector<const char *> articles = {"a", "an", "the"};

    list<string> list2(authors);  //  正确: 类型匹配
    // deque<string> authList(authors); // 错误: 容器类型不匹配
    // vector<string> words(articles);  // 错误: 容器类型必须匹配
    // 正确: 可以将const char*元素转换为string
    forward_list<string> words(articles.begin(), articles.end());
}

// 标准库array具有固定大小
void test3() {
    array<int, 10> ia1;  // 10个默认初始化的int
    array<int, 10> ia2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // 列表初始化
    array<int, 10> ia3 = {42}; // ia3[0]为42，剩余元素为0
    // 值得注意的是，虽然我们不能对内置数组类型进行拷贝或对象赋值，但array并无限制
    int digs[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int cpy[10] = digs;  // 错误: 内置数组不支持拷贝或赋值
    array<int, 10> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    array<int, 10> copy = digits; // 正确: 只要数组类型匹配即合法

}

// 使用swap
void test4() {
    vector<string> svec1(10);
    vector<string> svec2(24);
    swap(svec1, svec2);
}

// 插入范围内元素
void test5() {
    vector<string> v = {"quasi", "simba", "frollo", "scar"};
    vector<string> slist;
    // 将v的最后两个元素添加到slist的开始位置
    slist.insert(slist.begin(), v.end() - 2, v.end());
    slist.insert(slist.end(), {"these", "words", "will", "go", "at", "the", "end"});
    for (const auto &s: slist)
        cout << s << " ";
}

// 使用emplace操作
void test6() {
    list<Sales_data> c;
    // 使用三个参数的Sales_data构造函数
    c.emplace_back("978-0590353403", 25, 15.99);
    // 错误: 没有接受三个参数的push_back版本
    // c.push_back("978-0590353403", 25, 15.99);
    // 正确: 创建一个临时的Sales_data对象传递给push_back
    c.push_back(Sales_data("978-0590353403", 25, 15.99));
    auto iter = c.begin();
    c.emplace_back(); // 使用Sales_data的默认构造函数
    c.emplace(iter, "999-999999999");  // 使用Sales_data(String)
    // 使用Sales_data的接受一个ISBN、一个count和一个price的构造函数
    c.emplace_front("978-0590353403", 25, 15.99);
}

int main() {
    test5();
    return 0;
}