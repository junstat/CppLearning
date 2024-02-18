#include <iostream>
#include <string>

using namespace std;

// 结构体数组
// 1、定义结构体
struct Student {
    string name;
    int age;
    int score;
};

int main() {
    // 2、定义结构体数组
    Student stuArr[3] = {
            {"张山", 18, 90},
            {"李思", 28, 80},
            {"王武", 25, 85}
    };
    // 3、给结构体数组中的元素赋值
    stuArr[2].name = "赵留";
    stuArr[2].age = 32;
    stuArr[2].score = 60;

    // 4、遍历结构体数组
    for (const auto &item: stuArr)
        cout << "姓名: " << item.name
             << "，年龄: " << item.age
             << "，分数: " << item.score << endl;
    return 0;
}