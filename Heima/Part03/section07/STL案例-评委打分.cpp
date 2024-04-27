#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>
#include <deque>
#include <vector>

using namespace std;

/**
 * 有5名选手: 选手ABCDE, 10个评委分别对每一名选手打分，去除最高分，去除最低分，求平均分。
 */
// 选手类
class Person {
public:
    Person(string name, int score) : name(name), score(score) {
    }

    string name;
    int score;
};

void createPerson(vector<Person> &v) {
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5; i++) {
        string name = "选手";
        name += nameSeed[i];
        Person p(name, 0);
        v.push_back(p);
    }
}

// 打分
void setScore(vector<Person> &v) {
    for (auto &person: v) {
        deque<int> q;
        for (int i = 0; i < 10; i++) q.push_back(rand() % 41 + 60);

        // 排序
        sort(q.begin(), q.end());

        // 去除最高分和最低分
        q.pop_front();
        q.pop_back();

        // 求平均分
        int sum = 0;
        for (const auto &score: q) sum += score;
        person.score = sum / q.size();
    }
}

void showScore(vector<Person> &v) {
    for (const auto &person: v)
        cout << person.name << ": " << person.score << endl;
}

int main() {
    // 随机数种子
    srand((unsigned int)time(NULL));
    vector<Person> v;
    createPerson(v);

    setScore(v);

    showScore(v);
    return 0;
}