#include "Manager.h"

Manager::Manager(int id, string name, int dId) {
    this->id = id;
    this->name = name;
    this->deptId = dId;
}

void Manager::showInfo() {
    cout << "职工编号: " << this->id
         << "\t职工姓名: " << this->name
         << "\t岗位:" << this->getDeptName()
         << "\t岗位职责: 完成Boss交给的任务，并下发任务给普通员工" << endl;
}

string Manager::getDeptName() {
    return "经理";
}
