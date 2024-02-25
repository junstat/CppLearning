#include <iostream>
#include <string>

using namespace std;

#define MAX 1000

struct Person {
    string m_Name;
    int m_Sex; // 1 男， 2 女
    int m_Age;
    string m_Phone;
    string m_Addr;
};

struct AddressBooks {
    Person PersonArr[MAX];
    int m_Size;
};

// 封装函数显示界面
void showMenu() {
    cout << "***********************" << endl;
    cout << "***** 1. 添加联系人 *****" << endl;
    cout << "***** 2. 显示联系人 *****" << endl;
    cout << "***** 3. 删除联系人 *****" << endl;
    cout << "***** 4. 查找联系人 *****" << endl;
    cout << "***** 5. 修改联系人 *****" << endl;
    cout << "***** 6. 清空联系人 *****" << endl;
    cout << "***** 0. 退出通讯录 *****" << endl;
    cout << "***********************" << endl;
}

void addPerson(AddressBooks *abs) {
    // 判断通讯录是否已满，如果满了，就不再添加
    if (abs->m_Size == MAX) {
        cout << "通讯录已满，无法添加！" << endl;
        return;
    }

    // 添加联系人
    string name;
    cout << "请输入姓名：" << endl;
    cin >> name;
    abs->PersonArr[abs->m_Size].m_Name = name;

    cout << "请输入性别：" << endl;
    cout << "1 -- 男" << endl;
    cout << "2 -- 女" << endl;
    int sex = 0;
    while (true) {
        cin >> sex;
        if (sex == 1 || sex == 2) {
            abs->PersonArr[abs->m_Size].m_Sex = sex;
            break;
        }
        cout << "输入有误，请重新输入！" << endl;
    }

    cout << "请输入年龄：" << endl;
    int age = 0;
    cin >> age;
    abs->PersonArr[abs->m_Size].m_Age = age;

    cout << "请输入电话：" << endl;
    string phone;
    cin >> phone;
    abs->PersonArr[abs->m_Size].m_Phone = phone;

    cout << "请输入住址：" << endl;
    string address;
    cin >> address;
    abs->PersonArr[abs->m_Size].m_Addr = address;

    abs->m_Size++; // 通讯录中人数加1
    cout << "添加成功！" << endl;
    system("cls");
}

void showPerson(AddressBooks *abs) {
    if (abs->m_Size == 0) {
        cout << "当前记录为空！" << endl;
    }
    cout << "姓名\t\t性别\t\t年龄\t\t电话\t\t\t\t住址" << endl;
    for (int i = 0; i < abs->m_Size; i++) {
        cout << abs->PersonArr[i].m_Name << "\t\t";
        cout << (abs->PersonArr[i].m_Sex == 1 ? "男" : "女") << "\t\t";
        cout << abs->PersonArr[i].m_Age << "\t\t";
        cout << abs->PersonArr[i].m_Phone << "\t\t\t";
        cout << abs->PersonArr[i].m_Addr << endl;
    }
    system("cls");
}

// 检查联系人是否存在，如果存在则返回数组下标，不存在返回-1
int isExist(AddressBooks *abs, const string &name) {
    for (int i = 0; i < abs->m_Size; i++) {
        if (abs->PersonArr[i].m_Name == name) {
            return i;
        }
    }
    return -1;
}

// 删除联系人
void deletePerson(AddressBooks *abs) {
    cout << "请输入您要删除的联系人" << endl;
    string name;
    cin >> name;
    int idx = isExist(abs, name);
    if (idx == -1) {
        cout << "查无此人！" << endl;
        return;
    }
    for (int i = idx; i < abs->m_Size; i++) {
        abs->PersonArr[i] = abs->PersonArr[i + 1];
    }
    abs->m_Size--;
    cout << "删除成功！" << endl;
    system("cls");
}

// 查找联系人
void findPerson(AddressBooks *abs) {
    cout << "请输入您要查找的联系人" << endl;
    string name;
    cin >> name;
    int idx = isExist(abs, name);
    if (idx == -1) {
        cout << "查无此人！" << endl;
        return;
    }
    cout << "姓名\t\t性别\t\t年龄\t\t电话\t\t\t住址" << endl;
    cout << abs->PersonArr[idx].m_Name << "\t\t"
         << (abs->PersonArr[idx].m_Sex == 1 ? "男" : "女") << "\t\t"
         << abs->PersonArr[idx].m_Age << "\t\t"
         << abs->PersonArr[idx].m_Phone << "\t\t\t"
         << abs->PersonArr[idx].m_Addr << endl;
}

// 修改联系人
void modifyPerson(AddressBooks *abs) {
    cout << "请输入您要修改的联系人" << endl;
    string name;
    cin >> name;
    int idx = isExist(abs, name);
    if (idx == -1) {
        cout << "查无此人！" << endl;
        return;
    }
    cout << "姓名\t\t性别\t\t年龄\t\t电话\t\t\t住址" << endl;
    cout << "请输入姓名" << endl;
    cin >> name;
    abs->PersonArr[idx].m_Name = name;
    cout << "请输入性别" << endl;
    cout << "1 --- 男" << endl;
    cout << "2 --- 女" << endl;
    int sex = 0;
    while (true) {
        cin >> sex;
        if (sex == 1 || sex == 2) {
            abs->PersonArr[idx].m_Sex = sex;
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }
    cout << "请输入年龄" << endl;
    cin >> abs->PersonArr[idx].m_Age;
    cout << "请输入电话" << endl;
    cin >> abs->PersonArr[idx].m_Phone;
    cout << "请输入住址" << endl;
    cin >> abs->PersonArr[idx].m_Addr;
    cout << "修改成功！" << endl;
    system("cls");
}

// 清空所有联系人
void cleanPerson(AddressBooks *abs) {
    // 将当前记录联系人数量置为0，做逻辑清空操作
    abs->m_Size = 0;
    cout << "通讯录已清空！" << endl;
    system("cls");
}

int main() {
    AddressBooks abs; // 创建一个通讯录
    abs.m_Size = 0; // 初始化通讯录中人员个数

    int select = 0; // 创建用户选择输入的变量

    while (true) {
        showMenu();
        cin >> select;
        switch (select) {
            case 1: // 1. 添加联系人
                addPerson(&abs);
                break;
            case 2: // 2. 显示联系人
                showPerson(&abs);
                break;
            case 3: // 3. 删除联系人
                deletePerson(&abs);
                break;
            case 4: // 4. 查找联系人
                findPerson(&abs);
                break;
            case 5: // 5. 修改联系人
                modifyPerson(&abs);
                break;
            case 6: // 6. 清空联系人
                cleanPerson(&abs);
                break;
            case 0: // 0. 退出通讯录
                cout << "欢迎下次使用" << endl;
                return 0;
            default:
                break;
        }
    }
}