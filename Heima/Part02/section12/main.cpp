#include <iostream>
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
#include "WorkManager.h"

using namespace std;

void test1() {
    Worker *worker = nullptr;
    worker = new Employee(1, "张山", 1);
    worker->showInfo();
    delete worker;

    worker = new Manager(2, "李思", 2);
    worker->showInfo();
    delete worker;

    worker = new Boss(3, "王武", 3);
    worker->showInfo();
    delete worker;
}

int main() {
    WorkManager wm;

    int choice = 0;

    while (true) {
        wm.ShowMenu();
        cout << "请输入您的选择: " << endl;
        cin >> choice;

        switch (choice) {
            case 0: // 退出系统
                wm.ExitSystem();
                return 0;
            case 1:  // 增加职工
                wm.addEmp();
                break;
            case 2: // 显示职工
                wm.showEmp();
                break;
            case 3:  // 删除职工
                wm.delEmp();
                break;
            case 4:  // 修改职工
                wm.modEmp();
                break;
            case 5: // 查找职工
                wm.findEmp();
                break;
            case 6: // 排序职工
                wm.sortEmp();
                break;
            case 7: // 清空文档
                wm.cleanFile();
                break;
            default:
                system("cls");  // 清屏
                return 0;
        }
    }
}