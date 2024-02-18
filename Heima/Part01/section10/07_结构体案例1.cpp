#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// 学生的结构体
struct Student {
    string sName;
    int score;
};

struct Teacher {
    string tName;
    Student stu[5];
};

void allocateSpace(Teacher tArr[], int n) {
    string nameSeed = "ABCDE";
    for (int i = 0; i < n; ++i) {
        tArr[i].tName = "Teacher_";
        tArr[i].tName += nameSeed[i];
        for (int j = 0; j < 5; ++j) {
            tArr[i].stu[j].sName = "Student_";
            tArr[i].stu[j].sName += nameSeed[j];
            tArr[i].stu[j].score = rand() % 61 + 40;
        }
    }
}

void printInfo(Teacher tArr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "老师姓名: "
             << tArr[i].tName << endl;
        for (auto &j: tArr[i].stu) {
            cout <<
                 "\t学生姓名: " << j.sName
                 << "考试分数: " << j.score
                 << endl;
        }
    }
}

int main() {
    // 随机数种子
    srand((unsigned int) time(0));

    Teacher tArr[3];
    int n = sizeof(tArr) / sizeof(tArr[0]);
    allocateSpace(tArr, n);
    printInfo(tArr, n);
    return 0;
}