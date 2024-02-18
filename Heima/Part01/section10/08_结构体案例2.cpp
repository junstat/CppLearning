#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Hero {
    string name;
    int age;
    string sex;
};

void bubbleSort(Hero heroArr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (heroArr[j].age > heroArr[j + 1].age) {
                Hero temp = heroArr[j];
                heroArr[j] = heroArr[j + 1];
                heroArr[j + 1] = temp;
            }
        }
    }
}

void print(Hero heroArr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << i << "  " << heroArr[i].name << " " << heroArr[i].age << " " << heroArr[i].sex << endl;
    }
}

int main() {
    Hero heroArr[5] = {
            {"刘备", 23, "男"},
            {"关羽", 22, "男"},
            {"张飞", 20, "男"},
            {"赵云", 21, "男"},
            {"貂蝉", 19, "女"}
    };
    // bubbleSort(heroArr, 5);
    sort(begin(heroArr), end(heroArr), [](const Hero &a, const Hero &b) {
        return a.age < b.age;
    });
    print(heroArr, 5);
    return 0;
}