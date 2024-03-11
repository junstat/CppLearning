#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>

using namespace std;

/*
- 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
- 员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
- 随机给10名员工分配部门和工资
- 通过multimap进行信息的插入  key(部门编号) value(员工)
- 分部门显示员工信息
*/

#define CEHUA  0
#define MEISHU 1
#define YANFA  2

struct Worker {
    string name;
    int salary;
};

void createWorker(vector<Worker> &v) {
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++) {
        Worker worker;
        worker.name = "员工";
        worker.name += nameSeed[i];
        worker.salary = rand() % 10000 + 10000; // 10000 ~ 19999
        v.push_back(worker);
    }

}

// 员工分组
void setGroup(vector<Worker> &v, multimap<int, Worker> &m) {
    for (const auto &it: v) {
        int deptId = rand() % 3;
        m.insert(make_pair(deptId, it));
    }
}

void showWorker(multimap<int, Worker> &m, int deptId) {
    auto pos = m.find(deptId);
    auto count = m.count(deptId);
    int index = 0;
    for (; pos != m.end() && index < count; pos++, index++) {
        cout << "姓名: " << pos->second.name << ", 薪水: " << pos->second.salary << endl;
    }
}


void showWorkerByGroup(multimap<int, Worker> &m) {
    cout << "策划部门员工信息如下: " << endl;
    showWorker(m, CEHUA);
    cout << "---------------------------------------" << endl;

    cout << "美术部门员工信息如下: " << endl;
    showWorker(m, MEISHU);
    cout << "---------------------------------------" << endl;

    cout << "研发部门员工信息如下: " << endl;
    showWorker(m, YANFA);
    cout << "---------------------------------------" << endl;
}

int main() {
    srand((unsigned int) time(nullptr));
    // 1. 创建员工
    vector<Worker> v;
    createWorker(v);

    // 2. 员工分组
    multimap<int, Worker> m;
    setGroup(v, m);

    // 3. 分组显示员工
    showWorkerByGroup(m);


    // 测试
    for (const auto &it: v) {
        cout << "name: " << it.name << ", salary: " << it.salary << endl;
    }

    return 0;
}