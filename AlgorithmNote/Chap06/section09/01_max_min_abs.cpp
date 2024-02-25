#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


// 1. max min abs
void test1() {
    int x = 1, y = -2;
    cout << "max(x, y) = " << max(x, y) << endl;
    cout << "min(x, y) = " << min(x, y) << endl;
    cout << "abs(x) = " << abs(x) << ", abs(y) = " << abs(y) << endl;
}

// 2. swap
void test2() {
    int x = 1, y = 2;
    swap(x, y);
    cout << "x = " << x << ", y = " << y << endl;
}

// 3. reverse
void test3() {
    int a[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    reverse(a, a + 4);  // 将a[0]~a[3] 反转
    for (int i = 0; i < 6; ++i)
        cout << a[i] << " ";
    cout << endl;

    // 如果是对容器中的元素进行反转也是一样的
    string str = "abcdefghi";
    reverse(str.begin() + 2, str.begin() + 6); //  将str[2]~str[5] 反转
    cout << str << endl;
}

// 4. next_permutation
void test4() {
    int a[10] = {1, 2, 3};
    do {
        for (int i = 0; i < 3; ++i)
            cout << a[i] << " ";
        cout << endl;
    } while (next_permutation(a, a + 3));
}

// 5. fill
void test5() {
    int a[10];
    fill(a, a + 10, 233);  // 将a中的元素全部填充为0
    for (int i = 0; i < 10; ++i)
        cout << a[i] << " ";
    cout << endl;
}

// 6. sort
void test6() {
    // 1> 对int型数组排序
    int a[6] = {9, 4, 2, 5, 6, -1};
    // 将a[0] ~ a[3]
    sort(a, a + 4);
    for (const auto &x: a)
        cout << x << " ";
    cout << endl;
    // 将a[0] ~ a[5] 从小到大排序
    sort(a, a + 6);
    for (const auto &x: a)
        cout << x << " ";
    cout << endl;

    // 2> 对double型数组排序
    double b[] = {1.4, -2.1, 9, 2, 3};
    sort(b, b + 5);
    for (const auto &x: b)
        cout << x << " ";
    cout << endl;

    // 3> 对char型数组排序
    char c[] = {'T', 'W', 'A', 'K'};
    sort(c, c + 4);
    for (const auto &x: c)
        cout << x << " ";
    cout << endl;
}

// 7> sort 如何实现比较函数cmp
void test7() {
    // 1> int型数组进行排序
    int a[5] = {3, 1, 4, 2};
    sort(a, a + 5, [](int a, int b) { return a > b; });
    for (const auto &x: a)
        cout << x << " ";
    cout << endl;

    // 2> double型数组进行排序
    double b[5] = {3.1, 1.2, 4.3, 2.4};
    sort(b, b + 5, [](double a, double b) { return a > b; });
    for (const auto &x: b)
        cout << x << " ";
    cout << endl;

    // 3> char型数组进行排序
    char c[5] = {'T', 'W', 'A', 'K'};
    sort(c, c + 5, [](char a, char b) { return a > b; });
    for (const auto &x: c)
        cout << x << " ";
    cout << endl;
}

// 8> 结构体数组排序
struct node {
    int x, y;
};

void test8() {
    node ssd[3] = {
            {2, 2},
            {1, 3},
            {3, 1}
    };
    sort(ssd, ssd + 3, [](node a, node b) { return a.x > b.x; });
    for (const auto &n: ssd) {
        cout << n.x << " " << n.y << endl;
    }

    cout << endl;
    sort(ssd, ssd + 3, [](node a, node b) {
        if (a.x != b.x) return a.x > b.x;
        return a.y < b.y;
    });
    for (const auto &n: ssd) {
        cout << n.x << " " << n.y << endl;
    }
}

// 9> 容器的排序
void test9() {
    // 1> int型排序
    vector<int> vi = {3, 1, 2};
    sort(vi.begin(), vi.end(), [](int a, int b) { return a > b; });
    for (const auto &x: vi)
        cout << x << " ";
    cout << endl;

    // 2> str型排序
    string str[3] = {"bbbb", "cc", "aaa"};
    sort(str, str + 3);
    for (const auto &s: str)
        cout << s << " ";
    cout << endl;

    // 按string长度从小到大排序
    sort(str, str + 3, [](const string &a, const string &b) {
        return a.size() < b.size();
    });
    for (const auto &s: str)
        cout << s << " ";
    cout << endl;
}

// 10> lower_bound和upper_bound
// lower_bound和upper_bound需要用在一个有序数组或容器中
// lower_bound(first, last, val)返回[first, last)中第一个大于等于val的位置
// 如果是数组，则返回该位置的指针；如果是容器，则返回该位置的迭代器
// upper_bound(first, last, val)返回[first, last)中第一个大于val的位置
// 如果想获取下标，需要将结果减去数组首地址
void test10() {
    int a[] = {1, 2, 2, 3, 3, 3, 5, 5, 5, 5};
    // 寻找-1
    auto lowerPos = lower_bound(a, a + 10, -1);
    auto upperPos = upper_bound(a, a + 10, -1);
    cout << lowerPos - a << ", " << upperPos - a << endl;

    // 寻找3
    lowerPos = lower_bound(a, a + 10, 3);
    upperPos = upper_bound(a, a + 10, 3);
    cout << lowerPos - a << ", " << upperPos - a << endl;

    // 寻找4
    lowerPos = lower_bound(a, a + 10, 4);
    upperPos = upper_bound(a, a + 10, 4);
    cout << lowerPos - a << ", " << upperPos - a << endl;

    // 寻找6
    lowerPos = lower_bound(a, a + 10, 6);
    upperPos = upper_bound(a, a + 10, 6);
    cout << lowerPos - a << ", " << upperPos - a << endl;
}

int main() {
    test10();
    return 0;
}