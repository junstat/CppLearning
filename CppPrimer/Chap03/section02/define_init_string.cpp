#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>

using namespace std;

// 定义和初始化string对象
// 初始化string对象的方式
// string s1;  // 默认初始化，s1是一个空串
// string s2(s1); // s2是s1的副本
// string  s2 = s1; // 等价于s2(s1)，s2是s1的副本
// string s3("value"); // s3是字面值"value"的副本，除了字面值最后的那个空字符外
// string s3 = "value"; // 等价于s3("value")，s3是字面值"value"的副本
// string s4 = (n, 'c'); // 把s4初始化为由连续n个字符c组成的串


// 直接初始化和拷贝初始化
// 如果使用等号(=)初始化一个变量，实际上执行的是拷贝初始化(copy initialization)
// 编译器把等号右侧的初始值拷贝到新创建的对象中去
// 与之相反，如果不使用等号，则执行的是直接初始化(direct initialization)
string s5 = "hiya"; // 拷贝
string s6("hiya"); // 直接
string s7(10, 'c'); // 直接
string s8 = string(10, 'c'); // 拷贝

// string对象上的操作
// os << s  // 将s写到输出流os当中，返回os
// is >> s  // 从is中读取字符串赋给s，字符串以空白分隔，返回is
// getline(is, s); //  从is中读取一行赋给s，返回is
// s.empty()  // s为空返回ture，否则返回false
// s.size()  // 返回s中字符的个数
// s[n] // 返回s中第n个字符的引用，位置n从0计起
// s1+s2  // 返回s1和s2连接后的结果
// s1 = s2 // 用s2的副本代替s1中原来的字符串
// s1 == s2 // 如果s1和s2所含的字符完全一样，则它们相等; string对象的相等性判断对字母的大小写敏敢
// s1 != s2  // 等性判断对字母的大小写敏感
// <, <=, >, >= // 利用字符在字典中的顺序进行比较，且对字母的大小写敏感

// 读写string对象
void test1() {
    string s;
    cin >> s;
    cout << s << endl;
}

// 读取未知数量的string对象
void test2() {
    string word;
    while (cin >> word)
        cout << word << endl;
}

// 使用getline读取一整行
void test3() {
    string line;
    while (getline(cin, line))
        cout << line << endl;
}

// string的empty和size操作
void test4() {
    string line;
    while (getline(cin, line))
        if (!line.empty())
            cout << line << endl;
}

// size函数
void test5() {
    string line;
    while (getline(cin, line))
        if (line.size() > 80)
            cout << line << endl;
}

// string::size_type类型
// 它是一个无符号类型的值，而且能足够存放下任何string对象的大小。
// 所有用于存放string类的size函数返回值的变量，都应该是string::size_type类型
// 在C++11新标准中，允许编译器通过auto或者decltype来推断变量的类型
// 由于size函数返回的是一个无符号整型数，因此切记，如果在表达式中混用了
// 带符号数和无符号数将可能产生意想不到的结果。
void test6() {
    string line;
    auto len = line.size();
}


// cctype头文件中的函数
// isalnum(c); // 当c是字母或数字时为真
// isalpha(c); // 当c是字母时为真
// iscntrl(c);  // 当c是控制字符时为真
// isdigit(c);   // 当c是数字时为真
// isgraph(c);  // 当c不是空格但可打印时为真
// islower(c);  // 当c是小写字母时为真
// isprint(c);  // 当c是可打印字符时为真
// ispunct(c);  // 当c是标点符号时为真
// isspace(c);  // 当c是空格时为真
// isupper(c); // 当c是大写字母时为真
// isxdigit(c); // 当c是十六进制数字时为真
// tolower(c);  // 如果c是大写字母，则返回小写字母，否则返回c
// toupper(c);  // 如果c是小写字母，则返回大写字母，否则返回c
void test7() {
    string s("Hello World!!!");
    decltype(s.size()) punct_cnt = 0;
    for (auto c: s)
        if (ispunct(c))
            ++punct_cnt;
    cout << punct_cnt
         << " punctuation characters in " << s << endl;
}

int main() {
    test7();
    return 0;
}