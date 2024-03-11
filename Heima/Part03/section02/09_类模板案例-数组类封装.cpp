#include "ArrayT.hpp"
#include <string>

void printArray(ArrayT<int> &arr) {
    for (int i = 0; i < arr.getSize(); ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void test1() {
    ArrayT<int> arr1(10);
    // ArrayT<int> arr2(arr1);
    // ArrayT<int> arr3(100);
    // arr3 = arr1;
    for (int i = 0; i < 5; ++i)
        arr1.push_back(i);

    printArray(arr1);

    cout << "arr1的容量为:" << arr1.getCapacity() << endl;
    cout << "arr1的大小为:" << arr1.getSize() << endl;

    ArrayT<int> arr2(arr1);
    printArray(arr2);

    arr2.pop_back();
    cout << "arr2的容量为: " << arr2.getCapacity() << endl;
    cout << "arr2的大小为: " << arr2.getSize() << endl;
}

// 测试自定义数据类型
class Person {
public:
    Person() {}

    Person(string name, int age) : name(name), age(age) {}

    void show() {
        cout << "name: " << name << " ,age: " << age << endl;
    }

    string name;
    int age;
};

void printArrayPerson(ArrayT<Person> &arr) {
    for (int i = 0; i < arr.getSize(); ++i)
        arr[i].show();
}

void test2() {
    ArrayT<Person> arr(10);
    Person p1("孙悟空", 999);
    Person p2("韩信", 30);
    Person p3("妲己", 20);
    Person p4("赵云", 25);
    Person p5("安其拉", 27);

    arr.push_back(p1);
    arr.push_back(p2);
    arr.push_back(p3);
    arr.push_back(p4);
    arr.push_back(p5);

    printArrayPerson(arr);
    cout << "arr容量为: " << arr.getCapacity() << endl;
    cout << "arr大小为: " << arr.getSize() << endl;
}

int main() {
    test2();
    return 0;
}