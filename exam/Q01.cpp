#include <iostream>

using namespace std;

template<typename F>
int Use(F f) {
    static int count = 0;
    count++;
    return count;
}

void Func1() {}

void Func2() {}

class Functor {
public:
    void operator()() {}
};

int main() {
    Use(Func1);
    cout << Use(Func2);
    cout << Use(Functor());
    return 0;
}