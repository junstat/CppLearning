#include <iostream>

using namespace std;

class Person {
public:
    void showClassName() {
        cout << "Person" << endl;
    }

    void showAge() {
        // 报错原因是因为传入的指针是nullptr
        if (this == nullptr)
            return;
        cout << "age = " << this->age << endl;
    }

    int age;
};

int main() {
    Person *p = nullptr;
    p->showClassName();
    p->showAge();
    return 0;
}