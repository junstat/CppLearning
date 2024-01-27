#include <iostream>

using namespace std;

class BaseException {
};

class DerivedException : public BaseException {
};

int main() {
    try {
        BaseException *except = new DerivedException();
        throw *except;
    } catch (DerivedException &) {
        cout << "D";
    } catch (BaseException) {
        cout << "B";
    } catch (...) {
        cout << "O";
    }
    return 0;
}