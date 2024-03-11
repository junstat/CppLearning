#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

#define FILENAME "employee.txt"

using namespace std;

class WorkManager {
public:
    WorkManager();

    ~WorkManager();

    void ShowMenu();

    void ExitSystem();

    void addEmp();

    void save();

    int getEmpNum();

    // 初始化员工
    void initEmp();

    void showEmp();

    void delEmp();

    void modEmp();

    void findEmp();

    void sortEmp();

    void cleanFile();

    int isExist(int id);

    // 记录职工人数
    int empNum;

    // 职工数组指针
    Worker **empArr;

    // 判断文件是否为空标志
    bool fileIsEmpty;
};
