#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Person {
public:
    char name[64];
    int age;
};

void test1() {
    // 1. 包含头文件
    // 2. 创建输出流对象
    ofstream ofs("D:\\Documents\\Learn\\CLionProjects\\CppLearning\\Heima\\Part02\\section11\\person.txt",
                 ios::out | ios::binary);
    // 3. 打开文件
    // ofs.open("person.txt", ios::out | ios::binary);

    Person p = {"张山", 18};

    // 4. 写文件
    ofs.write((char *) &p, sizeof(p));

    // 5. 关闭文件
    ofs.close();
}

int main() {
    test1();
    return 0;
}