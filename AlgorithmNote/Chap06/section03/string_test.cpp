#include <iostream>
#include <string>

using namespace std;

// 1. string的定义
// string str = "abcd";

// 2. string中内容的访问
// (1) 通过下标访问，可以直接像字符数组那样去访问
void test1() {
    string str = "abcd";
    for (int i = 0; i < str.length(); i++) {
        cout << str[i] << " ";
    }
    cout << endl;
    // 用printf来输出string
    printf("%s\n", str.c_str());
}

// (2) 通过迭代器访问
void test2() {
    string str = "abcd";
    for (string::iterator it = str.begin(); it != str.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;;
}

// 3. string常用函数实例解析
// (1) operator+=  字符串拼接
void test3() {
    string str1 = "abcd";
    string str2 = "efgh";
    string str3 = str1 + str2;
    str1 += str2;
    cout << str3 << endl;
    cout << str1 << endl;
}

// (2) compare operator
void test4() {
    string str1 = "aa", str2 = "aaa", str3 = "abc", str4 = "xyz";
    if (str1 < str2) printf("ok1\n");  // 如果str1字典序小于str2，输出ok1
    if (str1 != str3) printf("ok2\n"); // 如果str1和str3不等，输出ok2
    if (str4 >= str3) printf("ok3\n"); // 如果str4字典序大于等于str3，输出ok3
}

// (3) length()/size() 返回string的长度，即存放的字符数，时间复杂度为O(1)

// (4) insert() 时间复杂度为O(N)
// - insert(pos, string) 在pos号位插入字符串 string
// - insert(it, it2, it3)
// it 为原字符串的欲插入位置，
// it2和it3为待插字符串的首尾迭代器，用来表示串[it2, it3)将被插在it的位置上
void test5() {
    string str = "abcxyz", str2 = "opq"; // str是原字符串，str2是待插字符串
    // 在str的3号位(即c和x之间)插入str2
    str.insert(str.begin() + 3, str2.begin(), str2.end());
    cout << str << endl;
}

// (5) erase()
// - erase(it) 用于删除单个元素
void test6() {
    string str = "abcdefg";
    str.erase(str.begin() + 4); // 删除4号位(即e)
    cout << str << endl;
}

// - erase(first, last) 删除[first, last)区间内的元素
void test7() {
    string str = "abcdefg";
    // 删除 cdef
    str.erase(str.begin() + 2, str.begin() - 1);
    cout << str << endl;
}

// - erase(pos, length), 其中pos为需要开始删除的起始位置，length为删除的字符个数
void test8() {
    string str = "abcdefg";
    str.erase(3, 2); // 删除从3号位开始的2个字符，即de
    cout << str << endl;
}

// 6. clear(): 用以清空string中的数据，时间复杂度一般为O(1)
void test9() {
    string str = "abcd";
    str.clear(); // 清空字符串
    cout << str.length() << endl;
}

// 7. substr(pos, length) 返回从pos号位开始、长度为length的子串
void test10() {
    string str = "Thank you for your smile.";
    cout << str.substr(0, 5) << endl;
    cout << str.substr(14, 4) << endl;
    cout << str.substr(19, 5) << endl;
}

// 8. string::npos 是一个常数，其本身为-1，但由于是unsigned_int类型
// 因此实际上也可以认为是unsigned_int类型的最大值。
// string::npos用以作为fid函数失配时的返回值。
void test11() {
    if (string::npos == -1) {
        cout << "-1 is true." << endl;
    }

    if (string::npos == 4294967295) {
        cout << "4294967295 is also true." << endl;
    }
}

// 9. find()
// str.find(str2) 当str2是str的子串时，返回其在str中第一次出现的位置；
// 如果str2不是str的子串，则返回string::npos。
// str.find(str2, pos) 当str的pos号位开始，str2是str的子串时，返回其与上相同
void test12() {
    string str = "Thank you for your smile.";
    string str2 = "you";
    string str3 = "me";
    if (str.find(str2) != string::npos) {
        cout << str.find(str2) << endl;
    }
    if (str.find(str2, 7) != string::npos) {
        cout << str.find(str2, 7) << endl;
    }
    if (str.find(str3) != string::npos) {
        cout << str.find(str3) << endl;
    } else {
        cout << "I know there is no position for me." << endl;
    }
}

// 10. replace
// str.replace(pos, len, str2) 把str从pos号位开始、长度为len的子串替换为str2。
// str.replace(it1, it2, str2) 把str的迭代器[it1, it2)范围的子串替换为str2。
void test13() {
    string str = "Maybe you will turn around.";
    string str2 = "will not";
    string str3 = "surely";
    cout << str.replace(10, 4, str2) << endl;
    cout << str.replace(str.begin(), str.begin() + 5, str3) << endl;
}


int main() {
    test13();
    return 0;
}