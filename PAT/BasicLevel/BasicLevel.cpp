//
// @Time   : 2021/1/14 20:30
// @Author : junstat@163.com

#include "BasicLevel.h"

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    basicLevel1016();
    return 0;
}