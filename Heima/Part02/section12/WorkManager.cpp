#include "WorkManager.h"

WorkManager::WorkManager() {
    // 1. 文件不存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open()) {
        cout << "文件不存在" << endl;
        this->empNum = 0;
        this->empArr = nullptr;
        this->fileIsEmpty = true;
        return;
    }

    // 2. 文件存在，数据为空
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        // cout << "文件为空" << endl;
        this->empNum = 0;
        this->empArr = nullptr;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }
    ifs.close();

    // 3. 文件存在，并且记录数据
    this->fileIsEmpty = false;
    int num = this->getEmpNum();
    cout << "职工人数为: " << num << endl;
    this->empNum = num;
    this->empArr = new Worker *[this->empNum];
    this->initEmp();

    this->showEmp();
}

WorkManager::~WorkManager() {

}

void WorkManager::ShowMenu() {
    cout << "********************************************" << endl;
    cout << "*********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void WorkManager::ExitSystem() {
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}

void WorkManager::addEmp() {
    cout << "请输入添加职工数量: " << endl;
    int addNum = 0;
    cin >> addNum;

    if (addNum > 0) {
        // 添加
        // 计算添加新空间大小
        int newSize = this->empNum + addNum;
        // 开辟新空间
        Worker **newSpace = new Worker *[newSize];
        // 将原来空间下数据，拷贝到新空间下
        if (this->empArr != nullptr) {
            for (int i = 0; i < this->empNum; ++i) {
                newSpace[i] = this->empArr[i];
            }
        }

        // 批量添加新数据
        for (int i = 0; i < addNum; ++i) {
            int id;
            string name;
            int dSelect;

            cout << "请输入第 " << i + 1 << " 个新职工编号: " << endl;
            cin >> id;

            cout << "请输入第 " << i + 1 << " 个新职工姓名: " << endl;
            cin >> name;

            cout << "请选择该职工岗位: " << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、Boss" << endl;

            cin >> dSelect;

            Worker *worker = nullptr;
            switch (dSelect) {
                case 1:
                    worker = new Employee(id, name, dSelect);
                    break;
                case 2:
                    worker = new Manager(id, name, dSelect);
                    break;
                case 3:
                    worker = new Boss(id, name, dSelect);
                    break;
                default:
                    cout << "输入的岗位有误" << endl;
                    break;
            }
            newSpace[this->empNum + i] = worker;
        }
        // 释放原有空间
        delete[] this->empArr;
        this->empArr = newSpace;
        this->empNum = newSize;
        this->fileIsEmpty = false;

        cout << "成功添加" << addNum << " 名新职工!" << endl;
        this->save();
    } else {
        cout << "输入数据有误" << endl;
    }
    system("pause");
    system("cls");
}

void WorkManager::save() {
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    for (int i = 0; i < this->empNum; ++i) {
        ofs << this->empArr[i]->id << " "
            << this->empArr[i]->name << " "
            << this->empArr[i]->deptId << endl;
    }

    ofs.close();
}

int WorkManager::getEmpNum() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int dId;

    int cnt = 0;

    while (ifs >> id && ifs >> name && ifs >> dId) {

        cnt++;
    }
    return cnt;
}

void WorkManager::initEmp() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;
    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId) {
        Worker *worker = nullptr;
        if (dId == 1) {
            worker = new Employee(id, name, dId);
        } else if (dId == 2) {
            worker = new Manager(id, name, dId);
        } else {
            worker = new Boss(id, name, dId);
        }
        this->empArr[index++] = worker;
    }

    ifs.close();
}

void WorkManager::showEmp() {
    if (this->fileIsEmpty) {
        cout << "文件不存在或记录为空!" << endl;
        return;
    }

    for (int i = 0; i < this->empNum; i++) {
        this->empArr[i]->showInfo();
    }
}

void WorkManager::delEmp() {
    if (this->fileIsEmpty) {
        cout << "文件不存在或记录为空!" << endl;
        return;
    }

    // 按id删
    cout << "请输入要删除的职工编号" << endl;
    int id = 0;
    cin >> id;

    int ret = isExist(id);
    if (ret != -1) {
        for (int i = ret; i < this->empNum - 1; i++) {
            this->empArr[i] = this->empArr[i + 1];
        }
        this->empNum--;
        if (this->empNum == 0) this->fileIsEmpty = true;
        this->save();
        cout << "删除成功!" << endl;
    } else {
        cout << "删除失败，未找到该职工!" << endl;
    }
    system("pause");
    system("cls");
}

int WorkManager::isExist(int id) {
    for (int i = 0; i < this->empNum; ++i) {
        if (this->empArr[i]->id == id) {
            return i;
        }
    }
    return -1;
}

void WorkManager::modEmp() {
    if (this->fileIsEmpty) {
        cout << "文件不存在或记录为空!" << endl;
        return;
    }

    cout << "请输入修改职工的编号: " << endl;
    int id;
    cin >> id;

    int ret = this->isExist(id);
    if (ret != -1) {
        delete this->empArr[ret];

        int newId = 0;
        string newName = "";
        int dSelect = 0;

        cout << "查到: " << id << " 号职工，请输入新职工号" << endl;
        cin >> newId;

        cout << "请输入新姓名:" << endl;
        cin >> newName;

        cout << "请输入岗位: " << endl;
        cout << "1、普通职工" << endl;
        cout << "2、经理" << endl;
        cout << "3、老板" << endl;

        cin >> dSelect;

        Worker *worker = nullptr;
        switch (dSelect) {
            case 1:
                worker = new Employee(newId, newName, dSelect);
                break;
            case 2:
                worker = new Manager(newId, newName, dSelect);
                break;
            case 3:
                worker = new Boss(newId, newName, dSelect);
                break;
            default:
                break;
        }
        this->empArr[ret] = worker;
        cout << "修改成功!" << endl;
        this->save();
    } else {
        cout << "修改失败，未找到该职工!" << endl;
    }

    system("pause");
    system("cls");
}

void WorkManager::findEmp() {
    if (this->fileIsEmpty) {
        cout << "文件不存在或记录为空!" << endl;
        return;
    }

    cout << "请输入查找的方式: " << endl;
    cout << "1、按职工编号查找" << endl;
    cout << "2、按职工姓名查找" << endl;

    int select = 0;
    cin >> select;

    if (select == 1) {   // 按id查
        int id;
        cout << "请输入查找的职工编号: " << endl;
        cin >> id;

        int ret = isExist(id);
        if (ret != -1) {
            cout << "查找成功！该职工信息如下: " << endl;
            this->empArr[ret]->showInfo();
        } else {
            cout << "查找失败，未找到该职工!" << endl;
        }
    } else if (select == 2) {  // 按姓名查
        string name;
        cout << "请输入查找的姓名: " << endl;
        cin >> name;

        bool found = false;

        for (int i = 0; i < this->empNum; ++i) {
            if (this->empArr[i]->name == name) {
                cout << "查找成功！该职工信息如下: " << endl;
                this->empArr[i]->showInfo();
                found = true;
                break;
            }
        }
        if (!found)
            cout << "查找失败，未找到该职工!" << endl;
    } else {
        cout << "输入选项有误！" << endl;
    }
    system("pause");
    system("cls");
}

void WorkManager::sortEmp() {
    if (this->fileIsEmpty) {
        cout << "文件不存在或记录为空!" << endl;
        system("pause");
        system("cls");
        return;
    }

    cout << "请选择排序方式: " << endl;
    cout << "1、按职工编号升序排序" << endl;
    cout << "2、按职工编号降序排序" << endl;

    int select = 0;
    cin >> select;

    for (int i = 0; i < this->empNum; ++i) {
        int minOrMax = i;
        for (int j = i + 1; j < this->empNum; ++j) {
            if (select == 1) {
                if (this->empArr[j]->id < this->empArr[minOrMax]->id)
                    minOrMax = j;
            } else {
                if (this->empArr[j]->id > this->empArr[minOrMax]->id)
                    minOrMax = j;
            }
        }
        if (i != minOrMax) {
            Worker *temp = this->empArr[i];
            this->empArr[i] = this->empArr[minOrMax];
            this->empArr[minOrMax] = temp;
        }
    }
    cout << "排序成功!排序后的结果为: " << endl;
    this->save();
    this->showEmp();
}

void WorkManager::cleanFile() {
    cout << "确定要清空文件吗?" << endl;
    cout << "1、确定" << endl;
    cout << "2、返回" << endl;

    char select;
    cin >> select;

    if (select == 1) {
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        if (this->empArr != nullptr) {
            for (int i = 0; i < this->empNum; ++i) {
                delete this->empArr[i];
                this->empArr[i] = nullptr;
            }

            delete[] this->empArr;
            this->empArr = nullptr;
            this->empNum = 0;
            this->fileIsEmpty = true;
        }
        cout << "清空成功!" << endl;
    }

    system("pause");
    system("cls");
}
