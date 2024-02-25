#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    Person(string name, int age) : name(name), age(age) {

    }

    bool operator==(const Person &other) const {
        return this->name == other.name && this->age == other.age;
    }

    bool operator!=(const Person &other) const {
        return !(*this == other);
    }

    string name;
    int age;
};

void test1() {
    Person p1("Tom", 18);
    Person p2("Frank", 18);
    if (p1 == p2) {
        cout << "p1 == p2" << endl;
    }
    if (p1 != p2) {
        cout << "p1 != p2" << endl;
    }
}

int main() {
    test1();
    return 0;
}