#include <iostream>
#include <vector>

using namespace std;

// 定义和初始化vector对象
// vector<T> v1; // v1是一个空vector，它潜在的元素是T类型的，执行默认初始化
// vector<T> v2(v1); // v2中包含有v1所有元素的副本
// vector<T> v2 = v1; // 等价于v2(v1)，v2中包含有v1所有元素的副本
// vector<T> v3(n, val); // v3包含了n个重复的元素，每个元素的值都是val
// vector<T> v4(n); // v4包含了n个重复地执行了值初始化的对象
// vector<T> v5{a, b, c}; // v5包含了初始值个数的元素，每个元素被赋予相应的初始值
// vector<T> v5 = {a, b, c}; // 等价于v5{a, b, c}

// 列表初始化vector对象
void test1() {
    vector<int> ivec;  // 初始状态为空
    vector<int> ivec2(ivec); // 拷贝
    vector<int> ivec3 = ivec; // 拷贝
    // vector<string> svec(ivec2); // 错误: svec的元素是string对象

    // 列表初始化
    vector<string> articles = {"a", "an", "the"};
    vector<string> v1{"a", "an", "the"}; // 列表初始化
    // vector<string> v2("a", "an", "the"); // 错误
}

void test2() {
    // 创建指定数量的元素
    vector<int> ivec(10, -1); // 10个int元素，每个都被初始化为-1
    vector<string> svec(10, "hi!"); // 10个string类型的元素，每个都被初始化为"hi!"
}

void test3() {
    // 值初始化(value-initialized)
    vector<int> ivec(10); // 10个元素，每个都初始化为0
    vector<string> svec(10); // 10个元素，每个都初始化为空string对象`
}

void test4() {
    // 列表初始值还是元素数量?
    vector<int> v1(10); // v1有10个元素，每个的值都是0
    vector<int> v2{10}; // v2有1个元素，元素的值是10
    vector<int> v3(10, 1); // v3有10个元素，每个的值都是1
    vector<int> v4{10, 1}; // v4有2个元素，元素的值分别是10和1
    vector<string> v5{"hi"}; // 列表初始化: v5有一个元素
    // vector<string> v6("hi"); // 错误: 不能使用字符串字面值构建vector对象
    vector<string> v7{10}; // v7有10个默认初始化的元素
    vector<string> v8{10, "hi"}; // v8有10个值为"hi"的元素
}

// 向vector对象中添加元素
void test5() {
    vector<int> v2; // 空vector对象
    for (int i = 0; i != 100; ++i)
        v2.push_back(i);  // 依次把整数值放到v2尾端

    // 从标准输入中读取单词，将其作为vector对象的元素存储
    string word;
    vector<string> text;
    while (cin >> word) {
        text.push_back(word); // 把word添加到text后面
    }
}

// 其他vector操作
// v.empty()  // 如果v不含有任何元素，返回真；否则返回假
// v.size()  // 返回v中元素的个数
// v.push_back(t)  // 向v的尾端添加一个值为t的元素
// v[n] // 返回v中第n个位置上元素的引用
// v1 = v2  // 用v2中的元素拷贝替换v1中的元素
// v1 = {a, b, c..};  // 用列表中元素的拷贝替换v1中的元素
// v1 == v2
// v1 != v2
// <, <=, >, >=

// 以10分为一个分数段统计成绩的数量
void test6() {
    freopen("D:\\Documents\\Learn\\CLionProjects\\CppLearning\\CppPrimer\\Chap03\\section03\\scores.txt", "r", stdin);
    vector<unsigned> scores(11, 0);
    unsigned grade;
    while (cin >> grade) {
        if (grade <= 100)
            ++scores[grade / 10];
    }

    for (const auto &item: scores)
        cout << item << " ";
}

int main() {
    test6();
    return 0;
}