#include <iostream>
#include <string>

using namespace std;

template<class NameType, class AgeType>
class Person {
public:
    Person(NameType name, AgeType age) : name(name), age(age) {}

    void showPerson() {
        cout << "name:" << name << " age:" << age << endl;
    }

    NameType name;
    AgeType age;
};

void test1() {
    Person<string, int> p1("孙悟空", 999);
    p1.showPerson();
}

int main() {
    test1();
    return 0;
}