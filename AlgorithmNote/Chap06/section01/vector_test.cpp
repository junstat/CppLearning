#include <iostream>
#include <vector>

using namespace std;

// vector 的定义与访问
void test1() {
    vector<int> vi;
    for (int i = 1; i <= 5; i++) {
        vi.push_back(i);
    }
    // vi.begin() 为取vi的首元素地址，而it指向这个地址
    auto it = vi.begin();
    for (int i = 0; i < 5; i++) {
        cout << *(it + i) << " "; // vi[i] 和 *(vi.begin() +i)是等价的
    }
    cout << endl;

    // vector的迭代器不支持 it < it.end()写法，因此循环条件只能用 it != vi.end()
    for (auto iter = vi.begin(); iter != vi.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

// vector 常用函数实例解析
// (1) push_back(x) 就是在vector后面添加一个元素x，时间复杂度为O(1)
// (2) pop_back() 就是删除vector最后一个元素，时间复杂度为O(1)
// (3) size() 获取vector中元素的个数，时间复杂度为O(1) size()返回的是unsigned类型
void test2() {
    vector<int> vi;
    for (int i = 1; i <= 3; i++) {
        vi.push_back(i);
    }

    vi.pop_back();
    for (int i = 0; i < vi.size(); i++)
        cout << vi[i] << " ";
    cout << endl;
}

// (4) clear() 清空vector中的所有元素，时间复杂度为O(n)
void test3() {
    vector<int> vi;
    for (int i = 1; i <= 3; i++) {
        vi.push_back(i);
    }
    vi.clear();
    cout << vi.size() << endl;
}

// (5) insert(it, x) 用来向vector的任意迭代器it处插入一个元素x，时间复杂度为O(n)
void test4() {
    vector<int> vi;
    for (int i = 1; i <= 5; i++) {
        vi.push_back(i);
    }
    vi.insert(vi.begin() + 2, -1);
    for (int i = 0; i < vi.size(); i++)
        cout << vi[i] << " ";
    cout << endl;
}

// (6)
// - erase(it)  删除单个元素
// - erase(first, last) 删除[first, last)内的所有元素
void test5() {
    vector<int> vi;
    for (int i = 1; i <= 5; i++) {
        vi.push_back(i);
    }
    vi.erase(vi.begin() + 3);
    for (int i = 0; i < vi.size(); i++) {
        cout << vi[i] << " ";
    }
    cout << endl;
    vi.erase(vi.begin() + 1, vi.begin() + 4);
    for (int i = 0; i < vi.size(); i++) {
        cout << vi[i] << " ";
    }
}


int main() {
    test5();
    return 0;
}