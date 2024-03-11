#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Person {
public:
    char name;
    int age;
};

void test1() {
    ifstream ifs("D:\\Documents\\Learn\\CLionProjects\\CppLearning\\Heima\\Part02\\section11\\person.txt",
                 ios::in | ios::binary);

    if (!ifs.is_open()) {
        cout << "文件打开失败！" << endl;
    }

    Person p;
    ifs.read((char *) &p, sizeof(Person));
    cout << "姓名: " << p.name << "年龄: " << p.age << endl;
}

int main() {
    test1();
    return 0;
}