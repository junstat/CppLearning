#include <iostream>
#include <fstream>

using namespace std;

void test1() {
    // 1. 包含头文件 fstream

    // 2. 创建流对象
    ofstream ofs;
    // 3. 指定打开方式
    ofs.open("D:\\Documents\\Learn\\CLionProjects\\CppLearning\\Heima\\Part02\\section11\\test.txt", ios::out);

    // 4. 写数据
    ofs << "姓名: 张山" << endl;
    ofs << "性别: 男" << endl;
    ofs << "年龄: 18" << endl;

    // 5. 关闭文件
    ofs.close();

}

int main() {
    test1();
    return 0;
}