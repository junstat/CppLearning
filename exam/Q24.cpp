#include <iostream>

using namespace std;

class Base {
public:
    static void Func() {
        cout << "Base::static Function" << endl;
    }
};

class Derived : public Base {
public:
    explicit Derived(int id) : id(id) {}

    static void Func() {
        cout << "Derived::static Function" << endl;
    }

private:
    int id;
};

void Test() {
    Derived a(0);
    Base b;
    a.Func();
    b.Func();

    Derived *c = new Derived(0);
    Base *d = c;
    c->Func();
    d->Func();

    delete c;
}

int main() {
    Test();
    return 0;
}